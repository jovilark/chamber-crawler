#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "utility.h"

class Entity {
public:
  Entity();
  virtual ~Entity() = 0;

  virtual int getHp() { return m_hp; }
  virtual int getAtk() { return m_atk; }
  virtual int getDef() { return m_def; }
  virtual int getAtkBonus() { return m_atkBonus; }
  virtual int getDefBonus() { return m_defBonus; }
  int getChamberNum() { return m_chamber; }

  virtual int value() { return m_value; }
  virtual Utility::Type type() { return m_type; }
  virtual bool invulnerable() { return true; }
  virtual void setHp(int hp) { m_hp = hp; }
  virtual void setAtk(int atk) { m_atk = atk; }
  virtual void setDef(int def) { m_def = def; }
  virtual void setAtkBonus(int bonus) { m_atkBonus = bonus; }
  virtual void setDefBonus(int bonus) { m_defBonus = bonus; }
  virtual void setValue(int value) { m_value = value; }
  virtual void setChamberNum(int chamber_num) { m_chamber = chamber_num; }
  virtual void setType(Utility::Type type) { m_type = type; }

  virtual Utility::Direction move();
  virtual int defend(float atk);
  virtual int attack(Entity *defender);
  virtual Utility::Effect interacted();
  virtual Utility::Effect collected();
  virtual bool permeable();
  virtual char draw();

private:
  int m_hp, m_atk, m_def, m_atkBonus, m_defBonus, m_value, m_chamber;
  Utility::Type m_type;
};

#endif // _ENTITY_H_