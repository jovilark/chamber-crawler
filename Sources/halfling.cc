#include "../Headers/halfling.h"

Halfling::Halfling() {
  setHp(Halfling::DEFAULT_HP);
  setMaxHp(Halfling::DEFAULT_HP);
  setAtk(Halfling::DEFAULT_ATK);
  setDef(Halfling::DEFAULT_DEF);
  setType(Utility::Type::Halfling);
}

char Halfling::draw() { return 'L'; }

int Halfling::defend(float atk) {
  bool miss = rand() % 2;
  if (miss)
    atk = 0;
  return Entity::defend(atk);
}