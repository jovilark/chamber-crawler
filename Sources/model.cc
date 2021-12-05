#include "../Headers/model.h"
#include "../Headers/chamber.h"
#include "../Headers/door.h"
#include "../Headers/drow.h"
#include "../Headers/dwarf.h"
#include "../Headers/elf.h"
#include "../Headers/floor.h"
#include "../Headers/goblin.h"
#include "../Headers/halfling.h"
#include "../Headers/human.h"
#include "../Headers/hwall.h"
#include "../Headers/merchant.h"
#include "../Headers/none.h"
#include "../Headers/orcs.h"
#include "../Headers/passage.h"
#include "../Headers/shade.h"
#include "../Headers/textview.h"
#include "../Headers/troll.h"
#include "../Headers/vampire.h"
#include "../Headers/vwall.h"
#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::make_unique;
using std::unordered_map;

Model::Model()
    : m_player{nullptr}, m_playerLoc{make_pair(-1, -1)}, m_move{true},
      m_view{make_unique<TextView>()}, m_entities{}, m_tiles{}, m_score{0} {}

void Model::generateChambers() {
  Chamber chamber1 = vector<Loc>{Loc(2, 2), Loc(29, 2), Loc(29, 7), Loc(2, 7)};
  Chamber chamber2 = vector<Loc>{
      Loc(38, 2), Loc(62, 2), Loc(62, 4),  Loc(70, 4),  Loc(70, 5), Loc(73, 5),
      Loc(73, 6), Loc(76, 6), Loc(76, 13), Loc(60, 13), Loc(60, 7), Loc(38, 7)};
  Chamber chamber3 =
      vector<Loc>{Loc(37, 9), Loc(50, 9), Loc(50, 13), Loc(37, 13)};
  Chamber chamber4 =
      vector<Loc>{Loc(3, 14), Loc(25, 14), Loc(25, 22), Loc(3, 22)};
  Chamber chamber5 = vector<Loc>{Loc(76, 15), Loc(76, 22), Loc(36, 22),
                                 Loc(36, 18), Loc(64, 18), Loc(64, 15)};
  m_chambers.push_back(chamber1);
  m_chambers.push_back(chamber2);
  m_chambers.push_back(chamber3);
  m_chambers.push_back(chamber4);
  m_chambers.push_back(chamber5);
}

Loc Model::LocInChamber(int chamber_num) {
  Loc l = NEEDS_RANDOM;
  while (!m_chambers[chamber_num].inChamber(l)) {
    l = make_pair(rand() % (m_chambers[chamber_num].upper_bound.first -
                            m_chambers[chamber_num].lower_bound.first - 1) +
                      m_chambers[chamber_num].lower_bound.first + 1,
                  rand() % (m_chambers[chamber_num].upper_bound.second -
                            m_chambers[chamber_num].lower_bound.second - 1) +
                      m_chambers[chamber_num].lower_bound.second + 1);
  }
  return l;
}

void Model::generateEnemies() {
  for (int i = 0; i < 20; i++) {
    int rand_num = rand() % 18;
    if (rand_num < 4) {
      generateCharacter<Human>();
    } else if (rand_num >= 4 && rand_num < 7) {
      generateCharacter<Dwarf>();
    } else if (rand_num >= 7 && rand_num < 12) {
      generateCharacter<Halfling>();
    } else if (rand_num >= 12 && rand_num < 14) {
      generateCharacter<Elf>();
    } else if (rand_num >= 14 && rand_num < 16) {
      generateCharacter<Orcs>();
    } else {
      generateCharacter<Merchant>();
    }
  }
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
  if (result) {
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
  for (int dX = -1; dX < 2; ++dX) {
    for (int dY = -1; dY < 2; ++dY) {
      if (dX == 0 && dY == 0)
        continue;

      Utility::Loc l =
          make_pair(m_playerLoc.first + dX, m_playerLoc.second + dY);
      auto &attacker = m_state[indiceFromLoc(l)];
      if (!attacker.second)
        continue;
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

bool Model::collect(Node &target) {
  if (!target.second)
    return false;
  bool result = parseEffect(target.second->collected());
  if (result) {
    removeEntity(target.second);
    target.second = nullptr;
  }
  return result;
}

bool Model::interact(Node &target) {
  if (!target.second)
    return false;
  bool result = parseEffect(target.second->interacted());
  if (result) {
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
  if (!target.first->permeable())
    return false;
  if (target.second) {
    if (!target.second->permeable())
      return false;
    else if (origin.second == m_player)
      collect(target);
  }
  target.second = origin.second;
  origin.second = nullptr;
  return true;
}

bool Model::attack(Node &attacker, Node &target) {
  if (!attacker.second)
    return false;
  if (!target.second)
    return false;

  int oldHp = target.second->getHp();
  int hp = attacker.second->attack(target.second);

  printAttack(attacker.second, target.second, oldHp - hp);

  bool died = hp <= 0;
  if (died) {
    removeEntity(target.second);
    target.second = nullptr;
  }
  return died;
}

void Model::removeEntity(Entity *e) {
  for (int i = 0; i < m_entities.size(); ++i) {
    auto &x = m_entities[i];
    if (x.get() == e) {
      m_entities.erase(m_entities.begin() + i);
      return;
    }
  }
}

void Model::printAttack(Entity *attacker, Entity *defender, int damage) {
  if (attacker == m_player)
    cout << "PC";
  else
    cout << Utility::typeToString(attacker->type());
  cout << " deals " << damage << " damage to ";
  if (defender == m_player)
    cout << "PC";
  else
    cout << Utility::typeToString(defender->type());
  cout << " (" << defender->getHp() << ")." << endl;
}

bool Model::parseEffect(Utility::Effect e) {
  switch (e) {
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
  return true;
}