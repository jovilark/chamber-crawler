#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "utility.h"

class Entity {
public:
  Entity();
  virtual ~Entity() = 0;

  virtual int getHp() { return m_hp; }
  virtual int getMaxHp() { return m_maxHp; }
  virtual int getAtk() { return m_atk; }
  virtual int getDef() { return m_def; }
  virtual int getAtkBonus() { return m_atkBonus; }
  virtual int getCurrentAtk() { return m_atk + m_atkBonus; }
  virtual int getDefBonus() { return m_defBonus; }
  virtual int getCurrentDef() { return m_def + m_defBonus; }
  virtual int getChamberNum() { return m_chamber; }
  virtual int getGold() { return m_gold; }
  virtual int getValue() { return m_value; }
  virtual Utility::Type getType() { return m_type; }
  virtual bool getHostile() { return m_hostile; }
  virtual int getScore() { return getGold(); }
  virtual Utility::Effect finished();
  virtual bool invulnerable() { return true; }
  virtual void setHp(int hp) { m_hp = hp > m_maxHp ? m_maxHp : hp; }
  virtual void setMaxHp(int hp) { m_maxHp = hp; }
  virtual void setAtk(int atk) { m_atk = atk; }
  virtual void setDef(int def) { m_def = def; }
  virtual void setAtkBonus(int bonus) {
    m_atkBonus = bonus < -m_atk ? -m_atk : bonus;
  }
  virtual void setDefBonus(int bonus) {
    m_defBonus = bonus < -m_def ? -m_def : bonus;
  }
  virtual void setValue(int value) { m_value = value; }
  virtual void setChamberNum(int chamber_num) { m_chamber = chamber_num; }
  virtual void setType(Utility::Type type) { m_type = type; }
  virtual void setGold(int gold) { m_gold = gold; }
  virtual void setHostile(bool hostile) { m_hostile = hostile; }
  virtual Utility::Direction move();
  virtual int defend(float atk);
  virtual int attack(Entity *defender);
  virtual Utility::Effect interacted();
  virtual Utility::Effect collected();
  virtual Utility::Effect died();
  virtual bool permeable();
  virtual char draw();

private:
  int m_hp, m_atk, m_def, m_atkBonus, m_defBonus, m_value, m_chamber, m_maxHp,
      m_gold;
  bool m_hostile;
  Utility::Type m_type;
};

#endif // _ENTITY_H_