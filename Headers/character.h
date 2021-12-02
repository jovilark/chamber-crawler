#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "entity.h"
#include "utility.h"

class Character : public Entity
{
public:
    Character();
    virtual ~Character() =0;

    bool invulnerable();
    Utility::Direction move();
private:
};

#endif // _CHARACTER_H_