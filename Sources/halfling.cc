#include "../Headers/halfling.h"

Halfling::Halfling()
{
    setHp(Halfling::DEFAULT_HP);
    setAtk(Halfling::DEFAULT_ATK);
    setDef(Halfling::DEFAULT_DEF);
}

char Halfling::draw()
{
    return 'L';
}