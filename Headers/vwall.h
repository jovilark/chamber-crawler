#ifndef _VWALL_H_
#define _VWALL_H_

#include "tile.h"

class VWall : public Tile {
public:
  bool permeable() { return false; }
  char draw() { return '|'; }
};

#endif // _VWALL_H_