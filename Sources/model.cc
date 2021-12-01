#include "../Headers/model.h"
#include "../Headers/door.h"
#include "../Headers/floor.h"
#include "../Headers/hwall.h"
#include "../Headers/none.h"
#include "../Headers/passage.h"
#include "../Headers/shade.h"
#include "../Headers/textview.h"
#include "../Headers/vwall.h"
#include "../Headers/dwarf.h"
#include <unordered_map>

using std::make_unique;

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
  // TODO: Cases for other races
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

  // Return if tile is occupied without moving.
  if (target.second && !target.second->permeable())
    return false;
  else if (!target.first->permeable())
    return false;

  // Move was successful. Update state.
  target.second = m_player;
  origin.second = nullptr;
  m_playerLoc = l;

  return true;
}

void Model::enemyMove() {
  std::unordered_map<Entity *, bool> moved;

  for (int i = 0; i < state().size(); ++i) {

    auto &origin = state()[i];
    if (!origin.second || moved[origin.second])
      continue;

    Utility::Direction d = origin.second->move();

    int x = i % BOARD_WIDTH;
    int y = i / BOARD_WIDTH;
    Utility::Loc l = make_pair(x, y);
    l = addDirectionToLoc(d, l);

    auto &target = state()[indiceFromLoc(l)];

    if (target.second)
      continue;

    moved[origin.second] = true;
    swapSpaces(origin, target);
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

void Model::swapSpaces(pair<Tile *, Entity *> p1, pair<Tile *, Entity *> p2) {
  Entity *tmp = p1.second;
  p1.second = p2.second;
  p2.second = tmp;
}