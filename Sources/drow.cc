#include "../Headers/drow.h"

Drow::Drow() {
  setHp(Drow::DEFAULT_HP);
  setAtk(Drow::DEFAULT_ATK);
  setDef(Drow::DEFAULT_DEF);
  setType(Utility::Type::Drow);
}

char Drow::draw() { return '@'; }