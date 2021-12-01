#include "../Headers/dwarf.h"

Dwarf::Dwarf()
{
    setHp(Dwarf::DEFAULT_HP);
    setAtk(Dwarf::DEFAULT_ATK);
    setDef(Dwarf::DEFAULT_DEF);
}

char Dwarf::draw()
{
    return 'W';
}