#ifndef _NONE_H_
#define _NONE_H_

#include "tile.h"

class None : public Tile {
public:
  bool permeable() { return false; }
  char draw() { return ' '; }
};

#endif // _NONE_H_
