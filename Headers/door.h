#ifndef _DOOR_H_
#define _DOOR_H_

#include "tile.h"

class Door : public Tile {
public:
  bool permeable() { return true; }
  char draw() { return '+'; }
};

#endif // _DOOR_H_