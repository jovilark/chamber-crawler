#include "../Headers/entity.h"
#include <cmath>
#include <iostream>

Entity::Entity() : m_hp{100}, m_atk{0}, m_def{0}, m_value{0}, m_type{Utility::Type::None} {}

Entity::~Entity() {}

Utility::Direction Entity::move() { return Utility::Direction::None; }

int Entity::defend(int atk) {
  if (invulnerable()) return hp();
  int damage = ceil((100.0f / (100.0f + (float)def())) * (float)atk);
  setHp(hp() - damage);
  return hp();
}

int Entity::attack(Entity *defender) { return defender->defend(atk()); }

Utility::Effect Entity::interacted() { return Utility::Effect::None; }

Utility::Effect Entity::collected() { return Utility::Effect::None; }

bool Entity::permeable() { return false; }

char Entity::draw() { return 'X'; }