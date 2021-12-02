#ifndef _ORCS_H_
#define _ORCS_H_

#include "character.h"

class Orcs : public Character
{
public:
    Orcs();
    ~Orcs() = default;
    char draw();
private:
    static const int DEFAULT_HP = 180;
    static const int DEFAULT_ATK = 30;
    static const int DEFAULT_DEF = 25;
};

#endif // _ORCS_H_
