#ifndef _MERCHANTTREASURE_H_
#define _MERCHANTTREASURE_H_

#include "item.h"

class MerchantTreasure : public Item {
public:
  MerchantTreasure();
  ~MerchantTreasure() = default;
  bool permeable();
  char draw();

private:
};

#endif // _MERCHANTTREASURE_H_