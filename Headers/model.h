#ifndef _MODEL_H_
#define _MODEL_H_

#include "utility.h"
#include "entity.h"
#include "tile.h"
#include "view.h"
#include "character.h"

using std::vector;
using std::unique_ptr;
using State = vector<pair<Tile *, Entity *>>;

static const Utility::Loc NEEDS_RANDOM = Utility::Loc(-1, -1);

class Model
{
public:
    Model();
    ~Model() = default;

    Entity *generateCharacter(Utility::Race race, Utility::Loc l = NEEDS_RANDOM);
    Entity *generatePlayer(Utility::Race race);
    Tile *generateTile(Utility::Terrain t);
    void generateLayout(vector<Utility::Terrain> layout);
    bool playerMove(Utility::Direction d);
    bool playerUse(Utility::Direction d);
    bool playerAttack(Utility::Direction d);
    void setEnemyMovement(bool move) { m_move = move; }
    void restart();
    void quit();
    State &state() { return m_state; }
    void render();
private:
    Entity *m_player;
    bool m_move;
    State m_state;
    unique_ptr<View> m_view;
    vector<unique_ptr<Entity>> m_entities;
    vector<unique_ptr<Tile>> m_tiles;
};

#endif // _MODEL_H_