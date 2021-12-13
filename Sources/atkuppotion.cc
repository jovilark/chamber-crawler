#include "../Headers/atkuppotion.h"

AtkUpPotion::AtkUpPotion() { setType(Utility::Type::AtkUpPotion); }

bool AtkUpPotion::permeable()
{
    return false;
}

char AtkUpPotion::draw()
{
    return 'P';
}

Utility::Effect AtkUpPotion::interacted()
{
    return Utility::Effect::AtkUp;
}