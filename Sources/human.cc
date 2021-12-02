#include "../Headers/human.h"

Human::Human()
{
    setHp(Human::DEFAULT_HP);
    setAtk(Human::DEFAULT_ATK);
    setDef(Human::DEFAULT_DEF);
}

char Human::draw()
{
    return 'H';
}