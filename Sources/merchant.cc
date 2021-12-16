#include "../Headers/merchant.h"

Merchant::Merchant() {
  setHp(Merchant::DEFAULT_HP);
  setMaxHp(Merchant::DEFAULT_HP);
  setAtk(Merchant::DEFAULT_ATK);
  setDef(Merchant::DEFAULT_DEF);
  setType(Utility::Type::Merchant);
  setHostile(false);
}

char Merchant::draw() { return 'M'; }

int Merchant::defend(float atk) {
  setHostile(true);
  return Entity::defend(atk);
}