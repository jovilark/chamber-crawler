#include "../Headers/model.h"
#include "../Headers/door.h"
#include "../Headers/dwarf.h"
#include "../Headers/floor.h"
#include "../Headers/hwall.h"
#include "../Headers/none.h"
#include "../Headers/passage.h"
#include "../Headers/shade.h"
#include "../Headers/textview.h"
#include "../Headers/vwall.h"
#include "../Headers/drow.h"
#include "../Headers/elf.h"
#include "../Headers/goblin.h"
#include "../Headers/halfling.h"
#include "../Headers/human.h"
#include "../Headers/merchant.h"
#include "../Headers/orcs.h"
#include "../Headers/troll.h"
#include "../Headers/vampire.h"
#include <unordered_map>
#include <iostream>

using std::make_unique;
using std::unordered_map;
using std::cout;
using std::endl;

Model::Model()
    : m_player{nullptr}, m_playerLoc{make_pair(-1, -1)}, m_move{true},
      m_view{make_unique<TextView>()}, m_entities{}, m_tiles{}, m_score{0} {}

Entity *Model::generateCharacter(Utility::Type Type, Utility::Loc l) {
  switch (Type) {
  case Utility::Type::Shade:
    m_entities.push_back(make_unique<Shade>());
    break;
  case Utility::Race::Drow:
    m_entities.push_back(make_unique<Drow>());
    break;
  case Utility::Race::Vampire:
    m_entities.push_back(make_unique<Vampire>());
    break;
  case Utility::Race::Troll:
    m_entities.push_back(make_unique<Troll>());
    break;
  case Utility::Race::Goblin:
    m_entities.push_back(make_unique<Goblin>());
    break;
  case Utility::Race::Human:
    m_entities.push_back(make_unique<Human>());
    break;
  case Utility::Race::Dwarf:
    m_entities.push_back(make_unique<Dwarf>());
    break;
  case Utility::Race::Elf:
    m_entities.push_back(make_unique<Elf>());
    break;
  case Utility::Race::Orcs:
    m_entities.push_back(make_unique<Orcs>());
    break;
  case Utility::Race::Merchant:
    m_entities.push_back(make_unique<Merchant>());
    break;
  case Utility::Race::Halfling:
    m_entities.push_back(make_unique<Halfling>());
    break;
  default:
    break;
  }

  Entity *character = m_entities.back().get();

  if (l == NEEDS_RANDOM) {
    // TODO: Random character location in a chamber
    // update 'l' with new random location.
  }

  m_state[indiceFromLoc(l)].second = character;
  return character;
}

Entity *Model::generatePlayer(Utility::Type Type) {
  // Temporarily assign a specified location until random works.
  m_playerLoc = make_pair(15, 15);
  m_player = generateCharacter(Type, m_playerLoc);

  return m_player;
}

void Model::generateEnemies()
{ 
  // If several spawn in same area, only last one is kept, other is lost
  // IT is possible to spawn someone outside the map, if giving out of bounds coordinates
  // Coordinates not accurate???
  generateCharacter(Utility::Race::Human, make_pair(18, 18));
  generateCharacter(Utility::Race::Dwarf, make_pair(18, 19));
  generateCharacter(Utility::Race::Elf, make_pair(18, 20));
  generateCharacter(Utility::Race::Orcs, make_pair(15, 21));
  generateCharacter(Utility::Race::Merchant, make_pair(18, 21));
  generateCharacter(Utility::Race::Halfling, make_pair(19, 21));
}

Tile *Model::generateTile(Utility::Terrain t) {
  switch (t) {
  case Utility::Terrain::Floor:
    m_tiles.push_back(make_unique<Floor>());
    break;
  case Utility::Terrain::Passage:
    m_tiles.push_back(make_unique<Passage>());
    break;
  case Utility::Terrain::Door:
    m_tiles.push_back(make_unique<Door>());
    break;
  case Utility::Terrain::HWall:
    m_tiles.push_back(make_unique<HWall>());
    break;
  case Utility::Terrain::VWall:
    m_tiles.push_back(make_unique<VWall>());
    break;
  default:
    m_tiles.push_back(make_unique<None>());
    break;
  }
  Tile *tile = m_tiles.back().get();
  m_state.push_back(make_pair(tile, nullptr));
  return tile;
}

void Model::generateLayout(vector<Utility::Terrain> layout) {
  for (auto t : layout)
    generateTile(t);
}

bool Model::playerMove(Utility::Direction d) {
  Utility::Loc l = Utility::addDirectionToLoc(d, m_playerLoc);
  auto &target = m_state[indiceFromLoc(l)];
  auto &origin = m_state[indiceFromLoc(m_playerLoc)];

  bool result = move(origin, target);
  if (result) 
  {
    m_playerLoc = l;
  }
  return result;
}

void Model::enemyMove() {
  unordered_map<Entity *, bool> moved;

  for (int i = 0; i < m_state.size(); ++i) {
    auto &origin = m_state[i];
    if (!origin.second || moved[origin.second] || origin.second == m_player)
      continue;

    Utility::Direction d = origin.second->move();

    int x = i % BOARD_WIDTH;
    int y = i / BOARD_WIDTH;
    Utility::Loc l = make_pair(x, y);
    l = addDirectionToLoc(d, l);

    auto &target = m_state[indiceFromLoc(l)];
    moved[origin.second] = move(origin, target);
  }
}

void Model::enemyAttack() {
  for (int dX = -1; dX < 2; ++dX)
  {
    for (int dY = -1; dY < 2; ++dY)
    {
      Utility::Loc l = make_pair(m_playerLoc.first + dX, m_playerLoc.second + dY);
      auto &attacker = m_state[indiceFromLoc(l)];
      if (!attacker.second) continue;
      auto &target = m_state[indiceFromLoc(m_playerLoc)];

      attack(attacker, target);
    }
  }
}

bool Model::playerUse(Utility::Direction d) {
  Utility::Loc l = Utility::addDirectionToLoc(d, m_playerLoc);
  auto &target = m_state[indiceFromLoc(l)];

  return interact(target);
}

// Returns true if an enemy was killed, false otherwise.
// Attempts to attack an enemy in the direction.
bool Model::playerAttack(Utility::Direction d) {
  Utility::Loc l = Utility::addDirectionToLoc(d, m_playerLoc);
  auto &attacker = m_state[indiceFromLoc(m_playerLoc)];
  auto &target = m_state[indiceFromLoc(l)];

  return attack(attacker, target);
}

bool Model::collect(Node &target)
{
  if (!target.second) return false;
  bool result = parseEffect(target.second->collected());
  if (result)
  {
    removeEntity(target.second);
    target.second = nullptr;
  }
  return result;
}

bool Model::interact(Node &target)
{
  if (!target.second) return false;
  bool result = parseEffect(target.second->interacted());
  if (result)
  {
    removeEntity(target.second);
    target.second = nullptr;
  }
  return result;
}

void Model::restart() {}

void Model::quit() {}

void Model::render() { m_view->render(m_state); }

int Model::indiceFromLoc(Utility::Loc l) {
  return l.first + l.second * BOARD_WIDTH;
}

bool Model::move(Node &origin, Node &target) {
  if (!target.first->permeable()) return false;
  if (target.second)
  {
    if (!target.second->permeable()) return false;
    else if (origin.second == m_player) collect(target);
  }
  target.second = origin.second;
  origin.second = nullptr;
  return true;
}

bool Model::attack(Node &attacker, Node &target)
{
  if (!attacker.second) return false;
  if (!target.second) return false;

  int oldHp = target.second->hp();
  int hp = attacker.second->attack(target.second);

  printAttack(attacker.second, target.second, oldHp - hp);

  bool died = hp <= 0;
  if (died)
  {
    removeEntity(target.second);
    target.second = nullptr;
  }
  return died;
}

void Model::removeEntity(Entity *e)
{
  for (int i = 0; i < m_entities.size(); ++i)
  {
    auto &x = m_entities[i];
    if (x.get() == e) 
    {
      m_entities.erase(m_entities.begin() + i);
      return;
    }
  }
}

void Model::printAttack(Entity *attacker, Entity *defender, int damage)
{
  if (attacker == m_player) cout << "PC";
  else cout << Utility::typeToString(attacker->type());
  cout << " deals " << damage << " damage to ";
  if (defender == m_player) cout << "PC";
  else cout << Utility::typeToString(defender->type());
  cout << " (" << defender->hp() << ")." << endl;
}

bool Model::parseEffect(Utility::Effect e)
{
  switch (e)
  {
  case Utility::Effect::SmallTreasure:
    m_score += 1;
    break;
  case Utility::Effect::NormalTreasure:
    m_score += 2;
    break;
  case Utility::Effect::MerchantTreasure:
    m_score += 4;
    break;
  case Utility::Effect::DragonTreasure:
    m_score += 6;
    break;
  case Utility::Effect::AtkUp:
    break;
  case Utility::Effect::AtkDown:
    break;
  case Utility::Effect::DefUp:
    break;
  case Utility::Effect::DefDown:
    break;
  default:
    return false;
  }
}