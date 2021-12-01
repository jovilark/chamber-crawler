#include "../Headers/atkeffect.h"

AtkEffect::AtkEffect(int val, Character *c) :
Decorator{c},
m_value{val}
{}

int AtkEffect::atk()
{
    return m_value + m_c->atk();
}