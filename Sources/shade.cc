#include "../Headers/shade.h"

Shade::Shade()
{
    setHp(Shade::DEFAULT_HP);
    setAtk(Shade::DEFAULT_ATK);
    setDef(Shade::DEFAULT_DEF);
}

char Shade::draw()
{
    return 'S';
}