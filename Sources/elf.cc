#include "../Headers/elf.h"

Elf::Elf() {
  setHp(Elf::DEFAULT_HP);
  setMaxHp(Elf::DEFAULT_HP);
  setAtk(Elf::DEFAULT_ATK);
  setDef(Elf::DEFAULT_DEF);
  setType(Utility::Type::Elf);
}

char Elf::draw() { return 'E'; }

int Elf::attack(Entity *defender) {
  int result = defender->defend(getCurrentAtk());
  if (defender->getType() != Utility::Type::Drow) result += defender->defend(getCurrentAtk());
  return result;
}