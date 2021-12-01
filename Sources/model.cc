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
#include <unordered_map>

using std::make_unique;
using std::unordered_map;

Model::Model()
    : m_player{nullptr}, m_playerLoc{make_pair(-1, -1)}, m_move{true},
      m_view{make_unique<TextView>()}, m_entities{}, m_tiles{} {}

Entity *Model::generateCharacter(Utility::Race race, Utility::Loc l) {
  switch (race) {
  case Utility::Race::Shade:
    m_entities.push_back(make_unique<Shade>());
    break;
  case Utility::Race::Dwarf:
    m_entities.push_back(make_unique<Dwarf>());
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

Entity *Model::generatePlayer(Utility::Race race) {
  // Temporarily assign a specified location until random works.
  m_playerLoc = make_pair(15, 15);
  m_player = generateCharacter(race, m_playerLoc);

  return m_player;
}

void Model::generateEnemies()
{
  generateCharacter(Utility::Race::Dwarf, make_pair(18, 18));
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
  if (result) m_playerLoc = l;
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

bool Model::playerUse(Utility::Direction d) {
  // Use and update state.
  return false;
}

bool Model::playerAttack(Utility::Direction d) {
  // Attack and update state.
  return false;
}

void Model::restart() {}

void Model::quit() {}

void Model::render() { m_view->render(m_state); }

int Model::indiceFromLoc(Utility::Loc l) {
  return l.first + l.second * BOARD_WIDTH;
}

bool Model::move(pair<Tile *, Entity *> &origin, pair<Tile *, Entity *> &target) {
  if (!target.first->permeable()) return false;
  if (target.second) return false; 
  Entity *tmp = origin.second;
  origin.second = target.second;
  target.second = tmp;
  return true;
}