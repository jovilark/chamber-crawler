#include "../Headers/goblin.h"

Goblin::Goblin() {
  setHp(Goblin::DEFAULT_HP);
  setAtk(Goblin::DEFAULT_ATK);
  setDef(Goblin::DEFAULT_DEF);
  setType(Utility::Type::Goblin);
}

char Goblin::draw() { return '@'; }