#ifndef _MODEL_H_
#define _MODEL_H_

#include "chamber.h"
#include "character.h"
#include "entity.h"
#include "tile.h"
#include "utility.h"
#include "view.h"
#include <iostream>

using std::make_unique;
using std::unique_ptr;
using std::vector;
using Node = pair<Tile *, Entity *>;
using State = vector<Node>;
using std::make_pair;

static const Utility::Loc NEEDS_RANDOM = make_pair(-1, -1);
static const int NEEDS_RANDOM_CHAMBER = -1;

class Model {
public:
  Model();
  ~Model() = default;
  void generateChambers();
  Loc LocInChamber(int chamber_num);
  template <typename EntityType>
  Entity *generateCharacter(Loc l = NEEDS_RANDOM,
                            int chamber_num = NEEDS_RANDOM_CHAMBER) {
    m_entities.push_back(make_unique<EntityType>());
    Entity *character = m_entities.back().get();
    if (chamber_num == NEEDS_RANDOM_CHAMBER) {
      character->setChamberNum(rand() % m_chambers.size());
    } else {
      character->setChamberNum(chamber_num);
    }
    if (l == NEEDS_RANDOM) {
      l = LocInChamber(character->getChamberNum());
    }
    while (m_state[indiceFromLoc(l)].second) {
      l = LocInChamber(character->getChamberNum());
    }
    m_state[indiceFromLoc(l)].second = character;
    return character;
  }
  template <typename EntityType> Entity *generatePlayer() {
    // Temporarily assign a specified location until random works.
    int chamber_num = rand() % m_chambers.size();
    m_playerLoc = LocInChamber(chamber_num);
    m_player = generateCharacter<EntityType>(m_playerLoc, chamber_num);
    return m_player;
  }

  void generateEnemies();

  template <typename TileType> Tile *generateTile() {
    m_tiles.push_back(make_unique<TileType>());
    Tile *tile = m_tiles.back().get();
    m_state.push_back(make_pair(tile, nullptr));
    return tile;
  }

  void generateLayout(vector<Utility::Terrain> layout);
  bool playerMove(Utility::Direction d);
  void enemyTurn();
  bool playerUse(Utility::Direction d);
  //void enemyAttack();
  bool playerAttack(Utility::Direction d);
  void setEnemyMovement(bool move) { m_move = move; }
  void restart();
  void quit();
  State &state() { return m_state; }
  void render();
  int indiceFromLoc(Utility::Loc l);

private:
  bool move(Node &origin, Node &target);
  bool attack(Node &attacker, Node &target);
  void removeEntity(Entity *e);
  void printAttack(Entity *attacker, Entity *defender, int damage);
  bool collect(Node &target);
  bool interact(Node &target);
  bool parseEffect(Utility::Effect e);
  Entity *m_player;
  Utility::Loc m_playerLoc;
  bool m_move;
  State m_state;
  unique_ptr<View> m_view;
  vector<unique_ptr<Entity>> m_entities;
  vector<unique_ptr<Tile>> m_tiles;
  vector<Chamber> m_chambers;
  int m_score;
};

#endif // _MODEL_H_