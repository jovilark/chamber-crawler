#include "../Headers/dragon.h"

Dragon::Dragon() {
  setHp(Dragon::DEFAULT_HP);
  setMaxHp(Dragon::DEFAULT_HP);
  setAtk(Dragon::DEFAULT_ATK);
  setDef(Dragon::DEFAULT_DEF);
  setType(Utility::Type::Dragon);
}

char Dragon::draw() { return 'D'; }

Utility::Direction Dragon::move() { return Utility::Direction::None; }