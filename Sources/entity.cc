#include "../Headers/entity.h"
#include <cmath>

Entity::Entity() : m_hp{0}, m_atk{0}, m_def{0} {}

Entity::~Entity() {}

Utility::Direction Entity::move() { return Utility::Direction::None; }

int Entity::defend(int atk) {
  int damage = ceil((100 / (100 + def())) * atk);
  setHp(hp() - damage);
  return hp();
}

int Entity::attack(Entity *defender) { return defender->defend(atk()); }

Utility::Effect Entity::interacted() { return Utility::Effect::None; }

Utility::Effect Entity::collected() { return Utility::Effect::None; }

bool Entity::permeable() { return false; }

char Entity::draw() { return 'X'; }
