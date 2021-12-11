#ifndef _DROW_H_
#define _DROW_H_

#include "character.h"

class Drow : public Character {
public:
  Drow();
  ~Drow() = default;
  char draw();

private:
  static const int DEFAULT_HP = 150;
  static const int DEFAULT_ATK = 25;
  static const int DEFAULT_DEF = 15;
};

#endif // _DROW_H_
