#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "character.h"

class Human : public Character
{
public:
    Human();
    ~Human() = default;
    char draw();
private:
    static const int DEFAULT_HP = 140;
    static const int DEFAULT_ATK = 20;
    static const int DEFAULT_DEF = 20;
};

#endif // _HUMAN_H_
