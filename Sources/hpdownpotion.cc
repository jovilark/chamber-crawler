#include "../Headers/hpdownpotion.h"

HpDownPotion::HpDownPotion() { setType(Utility::Type::HpDownPotion); }

bool HpDownPotion::permeable()
{
    return false;
}

char HpDownPotion::draw()
{
    return 'P';
}

Utility::Effect HpDownPotion::interacted()
{
    return Utility::Effect::HpDown;
}