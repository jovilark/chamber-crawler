#include "../Headers/human.h"

Human::Human()
{
    setHp(Human::DEFAULT_HP);
    setAtk(Human::DEFAULT_ATK);
    setDef(Human::DEFAULT_DEF);
    setType(Utility::Type::Human);
}

char Human::draw()
{
    return 'H';
}