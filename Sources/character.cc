#include "../Headers/character.h"
#include <cstdlib>

Character::Character() {
  setHostile(true);
}

Character::~Character() {}

bool Character::invulnerable() { return false; }

Utility::Direction Character::move() {
  int n = rand() % 8;
  return (Utility::Direction)n;
}

Utility::Effect Character::died() {
  return Utility::Effect::NormalTreasure;
}