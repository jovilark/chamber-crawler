#include "../Headers/dwarf.h"

Dwarf::Dwarf()
{
    setHp(Dwarf::DEFAULT_HP);
    setAtk(Dwarf::DEFAULT_ATK);
    setDef(Dwarf::DEFAULT_DEF);
    setType(Utility::Type::Dwarf);
}

bool Dwarf::invulnerable()
{
    return false;
}

char Dwarf::draw()
{
    return 'W';
}