#ifndef _GOBLIN_H_
#define _GOBLIN_H_

#include "character.h"

class Goblin : public Character {
public:
  Goblin();
  ~Goblin() = default;
  char draw();

private:
  static const int DEFAULT_HP = 110;
  static const int DEFAULT_ATK = 15;
  static const int DEFAULT_DEF = 20;
};

#endif // _GOBLIN_H_
