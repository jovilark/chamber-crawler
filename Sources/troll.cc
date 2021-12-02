#include "../Headers/troll.h"

Troll::Troll()
{
    setHp(Troll::DEFAULT_HP);
    setAtk(Troll::DEFAULT_ATK);
    setDef(Troll::DEFAULT_DEF);
}

char Troll::draw()
{
    return '@';
}