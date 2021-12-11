#ifndef _VIEW_H_
#define _VIEW_H_

#include "entity.h"
#include "tile.h"
#include <memory>
#include <vector>

using std::pair;
using std::vector;
using State = vector<pair<Tile *, Entity *>>;

static const int BOARD_WIDTH = 79;
static const int BOARD_HEIGHT = 30;

class View {
public:
  View();
  virtual ~View() = 0;
  virtual void render(State &s) = 0;
};

#endif // _VIEW_H_
