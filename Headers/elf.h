#ifndef _ELF_H_
#define _ELF_H_

#include "character.h"

class Elf : public Character
{
public:
    Elf();
    ~Elf() = default;
    char draw();
private:
    static const int DEFAULT_HP = 140;
    static const int DEFAULT_ATK = 30;
    static const int DEFAULT_DEF = 10;
};

#endif // _ELF_H_
