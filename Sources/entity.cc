#include "../Headers/entity.h"
#include <cmath>
#include <iostream>

Entity::Entity()
    : m_hp{100}, m_atk{0}, m_def{0}, m_atkBonus{0},
      m_defBonus{0}, m_value{0}, m_chamber{0}, m_maxHp{100}, m_gold{0},
      m_hostile{0}, m_type{Utility::Type::None} {}

Entity::~Entity() {}

Utility::Direction Entity::move() { return Utility::Direction::None; }

int Entity::defend(float atk) {
  if (invulnerable())
    return getHp();
  float def = getCurrentDef();
  int damage = ceil((100.0f / (100.0f + def)) * atk);
  setHp(getHp() - damage);
  return getHp();
}

int Entity::attack(Entity *defender) {
  return defender->defend(getCurrentAtk());
}

Utility::Effect Entity::interacted() { return Utility::Effect::None; }

Utility::Effect Entity::collected() { return Utility::Effect::None; }

Utility::Effect Entity::died() { return Utility::Effect::None; }

Utility::Effect Entity::finished() { return Utility::Effect::None; }

bool Entity::permeable() { return false; }

char Entity::draw() { return 'X'; }