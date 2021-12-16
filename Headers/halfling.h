#ifndef _HALFLING_H_
#define _HALFLING_H_

#include "character.h"

class Halfling : public Character {
public:
  Halfling();
  ~Halfling() = default;
  char draw();
  int defend(float atk);

private:
  static const int DEFAULT_HP = 100;
  static const int DEFAULT_ATK = 15;
  static const int DEFAULT_DEF = 20;
};

#endif // _HALFLING_H_
