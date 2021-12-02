#ifndef _SHADE_H_
#define _SHADE_H_

#include "character.h"

class Shade : public Character
{
public:
    Shade();
    ~Shade() = default;
    bool invulnerable() override;
    char draw();
private:
    static const int DEFAULT_HP = 125;
    static const int DEFAULT_ATK = 25;
    static const int DEFAULT_DEF = 25;
};

#endif // _SHADE_H_
