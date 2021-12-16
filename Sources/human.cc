#include "../Headers/human.h"

Human::Human() {
  setHp(Human::DEFAULT_HP);
  setMaxHp(Human::DEFAULT_HP);
  setAtk(Human::DEFAULT_ATK);
  setDef(Human::DEFAULT_DEF);
  setType(Utility::Type::Human);
}

char Human::draw() { return 'H'; }

Utility::Effect Human::died() {
  return Utility::Effect::MerchantTreasure;
}