#ifndef _STAIRCASE_H_
#define _STAIRCASE_H_
#include "item.h"

class Staircase : public Item {
public:
  Staircase();
  ~Staircase() = default;
  bool permeable() { return true; }
  char draw() { return '/'; }
  Utility::Effect collected() override;
};

#endif // _STAIRCASE_H_