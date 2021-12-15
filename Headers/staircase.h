#ifndef _STAIRCASE_H_
#define _STAIRCASE_H_
#include "entity.h"

class Staircase : public Entity {
public:
  bool permeable() { return true; }
  char draw() { return '/'; }
  Utility::Effect collected() override;
};

#endif // _STAIRCASE_H_