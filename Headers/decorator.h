#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include "character.h"

class Decorator : public Character
{
public:
    Decorator(Character *c);
protected:
    Character *m_c;
};

#endif // _DECORATOR_H_