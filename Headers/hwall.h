#ifndef _HWALL_H_
#define _HWALL_H_

#include "tile.h"

class HWall : public Tile
{
public:
    bool permeable() { return false; }
    char draw() { return '-'; }
};

#endif // _HWALL_H_