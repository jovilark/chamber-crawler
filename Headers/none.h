#ifndef _NONE_H_
#define _NONE_H_

class None : public Tile
{
public:
    bool permeable() { return false; }
    char draw() { return ' '; }
};

#endif // _NONE_H_
