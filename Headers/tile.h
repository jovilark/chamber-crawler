#ifndef _TILE_H_
#define _TILE_H_

class Tile
{
public:
    Tile();
    virtual ~Tile() =0;
    virtual bool permeable() =0;
    virtual char draw() =0;
};

#endif // _TILE_H_
