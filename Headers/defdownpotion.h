#ifndef _DEFDOWNPOTION_H_
#define _DEFDOWNPOTION_H_

#include "item.h"

class DefDownPotion : public Item {
public:
  DefDownPotion();
  ~DefDownPotion() = default;
  bool permeable();
  char draw();
  Utility::Effect interacted();

private:
};

#endif // _DEFDOWNPOTION_H_