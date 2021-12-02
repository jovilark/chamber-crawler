#ifndef _DWARF_H_
#define _DWARF_H_

#include "character.h"

class Dwarf : public Character
{
public:
    Dwarf();
    ~Dwarf() = default;
    bool invulnerable() override;
    char draw();
private:
    static const int DEFAULT_HP = 100;
    static const int DEFAULT_ATK = 20;
    static const int DEFAULT_DEF = 30;
};

#endif // _DWARF_H_
