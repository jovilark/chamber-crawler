#include "../Headers/defeffect.h"

DefEffect::DefEffect(int val, Character *c) : Decorator{c}, m_value{val} {}

int DefEffect::getDef() { return m_value + m_c->getDef(); }