#ifndef _DEFUPPOTION_H_
#define _DEFUPPOTION_H_

#include "item.h"

class DefUpPotion : public Item {
public:
  DefUpPotion();
  ~DefUpPotion() = default;
  bool permeable();
  char draw();
  Utility::Effect interacted();

private:
};

#endif // _DEFUPPOTION_H_