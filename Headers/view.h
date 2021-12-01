#ifndef _VIEW_H_
#define _VIEW_H_

#include <vector>
#include <memory>
#include "tile.h"
#include "entity.h"

using std::vector;
using std::pair;
using State = vector<pair<Tile *, Entity *>>;

static const int BOARD_WIDTH = 79;
static const int BOARD_HEIGHT = 30;

class View
{
public:
    View();
    virtual ~View() =0;
    virtual void render(State &s) =0;
};

#endif // _VIEW_H_
