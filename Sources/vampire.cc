#include "../Headers/vampire.h"
#include <climits>

Vampire::Vampire() {
  setHp(Vampire::DEFAULT_HP);
  setMaxHp(INT_MAX);
  setAtk(Vampire::DEFAULT_ATK);
  setDef(Vampire::DEFAULT_DEF);
  setType(Utility::Type::Vampire);
}

char Vampire::draw() { return '@'; }

int Vampire::attack(Entity *defender) { 
  int result = defender->defend(getCurrentAtk());
  if (result > 0) {
    if (defender->getType() == Utility::Type::Dwarf) setHp(getHp() - 5);
    else setHp(getHp() + 5);
  }
  return result;
}