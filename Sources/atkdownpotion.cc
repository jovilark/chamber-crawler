#include "../Headers/atkdownpotion.h"

AtkDownPotion::AtkDownPotion() { setType(Utility::Type::AtkDownPotion); }

bool AtkDownPotion::permeable()
{
    return false;
}

char AtkDownPotion::draw()
{
    return 'P';
}

Utility::Effect AtkDownPotion::interacted()
{
    return Utility::Effect::AtkDown;
}