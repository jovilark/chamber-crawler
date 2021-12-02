#include "../Headers/merchant.h"

Merchant::Merchant()
{
    setHp(Merchant::DEFAULT_HP);
    setAtk(Merchant::DEFAULT_ATK);
    setDef(Merchant::DEFAULT_DEF);
}

char Merchant::draw()
{
    return 'M';
}