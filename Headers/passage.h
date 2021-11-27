#ifndef _PASSAGE_H_
#define _PASSAGE_H_

#include "tile.h"

class Passage : public Tile
{
public:
    bool permeable() { return true; }
    char draw() { return '#'; }
};

#endif // _PASSAGE_H_