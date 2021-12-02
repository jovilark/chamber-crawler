#include "../Headers/drow.h"

Drow::Drow()
{
    setHp(Drow::DEFAULT_HP);
    setAtk(Drow::DEFAULT_ATK);
    setDef(Drow::DEFAULT_DEF);
}

char Drow::draw()
{
    return '@';
}