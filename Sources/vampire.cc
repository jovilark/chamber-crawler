#include "../Headers/vampire.h"

Vampire::Vampire()
{
    setHp(Vampire::DEFAULT_HP);
    setAtk(Vampire::DEFAULT_ATK);
    setDef(Vampire::DEFAULT_DEF);
}

char Vampire::draw()
{
    return '@';
}