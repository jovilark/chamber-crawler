#ifndef _TROLL_H_
#define _TROLL_H_

#include "character.h"

class Troll : public Character {
public:
  Troll();
  ~Troll() = default;
  char draw();
  Utility::Effect finished();
private:
  static const int DEFAULT_HP = 120;
  static const int DEFAULT_ATK = 25;
  static const int DEFAULT_DEF = 15;
};

#endif // _TROLL_H_
