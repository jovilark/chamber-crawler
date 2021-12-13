#include "../Headers/defdownpotion.h"

DefDownPotion::DefDownPotion() { setType(Utility::Type::DefDownPotion); }

bool DefDownPotion::permeable()
{
    return false;
}

char DefDownPotion::draw()
{
    return 'P';
}

Utility::Effect DefDownPotion::interacted()
{
    return Utility::Effect::DefDown;
}