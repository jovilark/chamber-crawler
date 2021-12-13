#ifndef _HPDOWNPOTION_H_
#define _HPDOWNPOTION_H_

#include "item.h"

class HpDownPotion : public Item {
public:
  HpDownPotion();
  ~HpDownPotion() = default;
  bool permeable();
  char draw();
  Utility::Effect interacted();

private:
};

#endif // _HPDOWNPOTION_H_