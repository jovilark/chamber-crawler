#include "../Headers/shade.h"

Shade::Shade() {
  setHp(Shade::DEFAULT_HP);
  setMaxHp(Shade::DEFAULT_HP);
  setAtk(Shade::DEFAULT_ATK);
  setDef(Shade::DEFAULT_DEF);
  setType(Utility::Type::Shade);
}

char Shade::draw() { return '@'; }

int Shade::getScore() { return getGold() * 1.5; }