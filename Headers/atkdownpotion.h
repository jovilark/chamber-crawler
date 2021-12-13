#ifndef _ATKDOWNPOTION_H_
#define _ATKDOWNPOTION_H_

#include "item.h"

class AtkDownPotion : public Item {
public:
  AtkDownPotion();
  ~AtkDownPotion() = default;
  bool permeable();
  char draw();
  Utility::Effect interacted();

private:
};

#endif // _ATKDOWNPOTION_H_