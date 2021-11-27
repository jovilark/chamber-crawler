#include "../Headers/defeffect.h"

DefEffect::DefEffect(int val, Character *c) :
Decorator{c},
m_value{val}
{}

int DefEffect::def()
{
    return m_value + m_c->def();
}