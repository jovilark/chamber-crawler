#ifndef _NORMALTREASURE_H_
#define _NORMALTREASURE_H_

#include "item.h"

class NormalTreasure : public Item {
public:
  NormalTreasure();
  ~NormalTreasure() = default;
  bool permeable();
  char draw();

private:
};

#endif // _NORMALTREASURE_H_