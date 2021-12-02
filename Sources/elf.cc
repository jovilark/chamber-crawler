#include "../Headers/elf.h"

Elf::Elf()
{
    setHp(Elf::DEFAULT_HP);
    setAtk(Elf::DEFAULT_ATK);
    setDef(Elf::DEFAULT_DEF);
    setType(Utility::Type::Elf);
}

char Elf::draw()
{
    return 'E';
}