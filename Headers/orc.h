#ifndef _ORC_H_
#define _ORC_H_

#include "character.h"

class Orc : public Character {
public:
  Orc();
  ~Orc() = default;
  char draw();
  int attack(Entity *defender);

private:
  static const int DEFAULT_HP = 180;
  static const int DEFAULT_ATK = 30;
  static const int DEFAULT_DEF = 25;
};

#endif // _ORC_H_
