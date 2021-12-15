#include "../Headers/vampire.h"

Vampire::Vampire() {
  setHp(Vampire::DEFAULT_HP);
  setMaxHp(99999);
  setAtk(Vampire::DEFAULT_ATK);
  setDef(Vampire::DEFAULT_DEF);
  setType(Utility::Type::Vampire);
}

char Vampire::draw() { return '@'; }