#include "../Headers/orc.h"

Orc::Orc() {
  setHp(Orc::DEFAULT_HP);
  setMaxHp(Orc::DEFAULT_HP);
  setAtk(Orc::DEFAULT_ATK);
  setDef(Orc::DEFAULT_DEF);
  setType(Utility::Type::Orc);
}

char Orc::draw() { return 'O'; }

int Orc::attack(Entity *defender) {
  int atk = getCurrentAtk();
  if (defender->getType() == Utility::Type::Goblin) atk *= 1.5;
  return defender->defend(atk); 
}