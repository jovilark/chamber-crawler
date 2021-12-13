#ifndef _ATKUPPOTION_H_
#define _ATKUPPOTION_H_

#include "item.h"

class AtkUpPotion : public Item {
public:
  AtkUpPotion();
  ~AtkUpPotion() = default;
  bool permeable();
  char draw();
  Utility::Effect interacted();

private:
};

#endif // _ATKUPPOTION_H_