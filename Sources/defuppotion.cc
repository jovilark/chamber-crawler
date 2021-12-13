#include "../Headers/defuppotion.h"

DefUpPotion::DefUpPotion() { setType(Utility::Type::DefUpPotion); }

bool DefUpPotion::permeable()
{
    return false;
}

char DefUpPotion::draw()
{
    return 'P';
}

Utility::Effect DefUpPotion::interacted()
{
    return Utility::Effect::DefUp;
}