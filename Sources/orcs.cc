#include "../Headers/orcs.h"

Orcs::Orcs() {
  setHp(Orcs::DEFAULT_HP);
  setAtk(Orcs::DEFAULT_ATK);
  setDef(Orcs::DEFAULT_DEF);
  setType(Utility::Type::Orcs);
}

char Orcs::draw() { return 'O'; }