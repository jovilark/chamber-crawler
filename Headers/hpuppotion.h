#ifndef _HPUPPOTION_H_
#define _HPUPPOTION_H_

#include "item.h"

class HpUpPotion : public Item {
public:
  HpUpPotion();
  ~HpUpPotion() = default;
  bool permeable();
  char draw();
  Utility::Effect interacted();

private:
};

#endif // _HPUPPOTION_H_