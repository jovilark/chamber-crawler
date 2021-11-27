#include "../Headers/character.h"
#include <cstdlib>

Character::Character() {}

Character::~Character() {}

Utility::Direction Character::move()
{
    int n = rand() % 8;
    return (Utility::Direction)n;
}