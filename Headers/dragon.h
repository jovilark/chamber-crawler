#ifndef _DRAGON_H_
#define _DRAGON_H_

#include "character.h"

class Dragon : public Character {
public:
  Dragon();
  ~Dragon() = default;
  char draw();
  Utility::Direction move() override;

private:
  static const int DEFAULT_HP = 150;
  static const int DEFAULT_ATK = 20;
  static const int DEFAULT_DEF = 20;
};

#endif // _DRAGON_H_
