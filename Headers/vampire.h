#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_

#include "character.h"

class Vampire : public Character
{
public:
    Vampire();
    ~Vampire() = default;
    char draw();
private:
    static const int DEFAULT_HP = 50;
    static const int DEFAULT_ATK = 25;
    static const int DEFAULT_DEF = 25;
};

#endif // _VAMPIRE_H_
