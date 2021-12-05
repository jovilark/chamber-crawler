#ifndef _DEFEFFECT_H_
#define _DEFEFFECT_H_

#include "character.h"
#include "decorator.h"

class DefEffect : public Decorator {
public:
  DefEffect(int val, Character *c);
  ~DefEffect() = default;
  int getDef() override;

private:
  int m_value;
};

#endif // _DEFEFFECT_H_