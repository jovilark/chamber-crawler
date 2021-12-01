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

  Entity *generateCharacter(Utility::Race race, Utility::Loc l = NEEDS_RANDOM);
  Entity *generatePlayer(Utility::Race race);
  void generateEnemies();
  Tile *generateTile(Utility::Terrain t);
  void generateLayout(vector<Utility::Terrain> layout);
  bool playerMove(Utility::Direction d);
  void enemyMove();
  bool playerUse(Utility::Direction d);
  bool playerAttack(Utility::Direction d);
  void setEnemyMovement(bool move) { m_move = move; }
  void restart();
  void quit();
  State &state() { return m_state; }
  void render();
  int indiceFromLoc(Utility::Loc l);

private:
  void swapSpaces(pair<Tile *, Entity *> p1, pair<Tile *, Entity *> p2);
  Entity *m_player;
  Utility::Loc m_playerLoc;
  bool m_move;
  State m_state;
  unique_ptr<View> m_view;
  vector<unique_ptr<Entity>> m_entities;
  vector<unique_ptr<Tile>> m_tiles;
};

#endif // _MODEL_H_