#ifndef _MODEL_H_
#define _MODEL_H_

#include "character.h"
#include "entity.h"
#include "tile.h"
#include "utility.h"
#include "view.h"

using std::unique_ptr;
using std::vector;
using State = vector<pair<Tile *, Entity *>>;
using std::make_pair;

static const Utility::Loc NEEDS_RANDOM = make_pair(-1, -1);

class Model {
public:
  Model();
  ~Model() = default;

  Entity *generateCharacter(Utility::Type Type, Utility::Loc l = NEEDS_RANDOM);
  Entity *generatePlayer(Utility::Type Type);
  void generateEnemies();
  Tile *generateTile(Utility::Terrain t);
  void generateLayout(vector<Utility::Terrain> layout);
  bool playerMove(Utility::Direction d);
  void enemyMove();
  bool playerUse(Utility::Direction d);
  void enemyAttack();
  bool playerAttack(Utility::Direction d);
  void setEnemyMovement(bool move) { m_move = move; }
  void restart();
  void quit();
  State &state() { return m_state; }
  void render();
  int indiceFromLoc(Utility::Loc l);

private:
  bool move(pair<Tile *, Entity *> &origin, pair<Tile *, Entity *> &target);
  bool attack(pair<Tile *, Entity *> &attacker, pair<Tile *, Entity *> &target);
  void removeEntity(Entity *e);
  void printAttack(Entity *attacker, Entity *defender, int damage);
  Entity *m_player;
  Utility::Loc m_playerLoc;
  bool m_move;
  State m_state;
  unique_ptr<View> m_view;
  vector<unique_ptr<Entity>> m_entities;
  vector<unique_ptr<Tile>> m_tiles;
};

#endif // _MODEL_H_