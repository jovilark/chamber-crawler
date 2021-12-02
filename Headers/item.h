#ifndef _ITEM_H_
#define _ITEM_H_

#include "entity.h"

class Item : public Entity
{
public:
    Item();
    virtual ~Item() =0;
private:
};

#endif // _ITEM_H_