#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "utility.h"

class Entity {
public:
  Entity();
  virtual ~Entity() = 0;

  virtual int hp() { return m_hp; }
  virtual int atk() { return m_atk; }
  virtual int def() { return m_def; }
  void setHp(int hp) { m_hp = hp; }
  void setAtk(int atk) { m_atk = atk; }
  void setDef(int def) { m_def = def; }

  virtual Utility::Direction move();
  virtual int defend(int atk);
  virtual int attack(Entity *defender);
  virtual Utility::Effect interacted();
  virtual Utility::Effect collected();
  virtual bool permeable();
  virtual char draw();

private:
  int m_hp, m_atk, m_def;
};

#endif // _ENTITY_H_