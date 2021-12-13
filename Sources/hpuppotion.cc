#include "../Headers/hpuppotion.h"

HpUpPotion::HpUpPotion() { setType(Utility::Type::HpUpPotion); }

bool HpUpPotion::permeable()
{
    return false;
}

char HpUpPotion::draw()
{
    return 'P';
}

Utility::Effect HpUpPotion::interacted()
{
    return Utility::Effect::HpUp;
}