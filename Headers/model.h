#ifndef _MODEL_H_
#define _MODEL_H_

#include "chamber.h"
#include "character.h"
#include "entity.h"
#include "tile.h"
#include "utility.h"
#include <iostream>
#include <memory>
#include <unordered_map>

using std::make_unique;
using std::unique_ptr;
using std::vector;
using Node = pair<Tile *, Entity *>;
using State = vector<Node>;
using std::make_pair;
using std::unordered_map;

static const Utility::Loc NEEDS_RANDOM = make_pair(-1, -1);
static const int NEEDS_RANDOM_CHAMBER = -1;

class Model {
public:
  Model();
  ~Model() = default;
  void generateChambers();
  Loc LocInChamber(int chamber_num);

  template <typename EntityType>
  Loc generateEntity(Loc l = NEEDS_RANDOM,
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
    return l;
  }

  template <typename EntityType> Entity *generatePlayer() {
    // Temporarily assign a specified location until random works.
    int chamber_num = rand() % m_chambers.size();
    m_playerLoc = LocInChamber(chamber_num);
    generateEntity<EntityType>(m_playerLoc, chamber_num);
    m_player = m_entities.back().get();
    return m_player;
  }

  void generateEnemies(int n);
  void generatePotions(int n);
  void generateTreasure(int n);

  template <typename TileType> Tile *generateTile() {
    m_tiles.push_back(make_unique<TileType>());
    Tile *tile = m_tiles.back().get();
    m_state.push_back(make_pair(tile, nullptr));
    return tile;
  }

  void generateLayout(vector<Utility::Terrain> layout);
  bool playerMove(Utility::Direction d);
  void enemyTurn(bool move);
  bool playerUse(Utility::Direction d);
  bool playerAttack(Utility::Direction d);
  void setEnemyMovement(bool move) { m_move = move; }
  bool getEnemyMovement() { return m_move; }
  State &state() { return m_state; }
  int indiceFromLoc(Utility::Loc l);
  Entity *getPlayer() { return m_player; }
  int getScore() { return m_player->getGold(); }
  string getTurnDesc() { return turn_desc; }
  void resetTurnDesc() { turn_desc = ""; }
  void setNextFloor (bool b) { to_next_floor = b; }
  bool toNextFloor() { return to_next_floor; }
  int getFloor() { return m_floor; }
  void nextFloor() { ++m_floor; }
  void resetEntities();
  void generateLevel();
  int getNonPlayerChamber();
  void playerDead();

private:
  bool move(Node &origin, Node &target);
  bool attack(Node &attacker, Node &target);
  void removeEntity(Entity *e);
  void printAttack(Entity *attacker, Entity *defender, int damage);
  bool collect(Node &target);
  bool interact(Node &target);
  bool parseEffect(Utility::Effect e);
  void printMove(Utility::Direction d);
  vector<Utility::Type> scout();
  Entity *m_player;
  Utility::Loc m_playerLoc;
  bool m_move;
  bool to_next_floor = false;
  State m_state;
  string turn_desc;
  vector<unique_ptr<Entity>> m_entities;
  vector<unique_ptr<Tile>> m_tiles;
  vector<Chamber> m_chambers;
  int m_floor;
  unordered_map<Utility::Type, bool> m_potions;
};

#endif // _MODEL_H_