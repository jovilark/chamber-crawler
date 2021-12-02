#ifndef _SMALLTREASURE_H_
#define _SMALLTREASURE_H_

#include "item.h"

class SmallTreasure : public Item
{
public:
    SmallTreasure();
    ~SmallTreasure() = default;
    bool permeable();
    char draw();
private:
};

#endif // _SMALLTREASURE_H_