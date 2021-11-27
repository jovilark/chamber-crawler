#ifndef _ATKEFFECT_H_
#define _ATKEFFECT_H_

#include "character.h"
#include "decorator.h"

class AtkEffect : public Decorator
{
public:
    AtkEffect(int val, Character *c);
    int atk() override;
private:
    int m_value;
};

#endif // _ATKEFFECT_H_