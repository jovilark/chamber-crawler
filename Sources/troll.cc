#include "../Headers/troll.h"

Troll::Troll() {
  setHp(Troll::DEFAULT_HP);
  setMaxHp(Troll::DEFAULT_HP);
  setAtk(Troll::DEFAULT_ATK);
  setDef(Troll::DEFAULT_DEF);
  setType(Utility::Type::Troll);
}

char Troll::draw() { return '@'; }