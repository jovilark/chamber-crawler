#ifndef _DRAGONTREASURE_H_
#define _DRAGONTREASURE_H_

#include "item.h"

class DragonTreasure : public Item {
public:
  DragonTreasure();
  ~DragonTreasure() = default;
  bool permeable();
  char draw();
  Utility::Effect collected();

private:
};

#endif // _DRAGONTREASURE_H_