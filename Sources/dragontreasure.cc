#include "../Headers/dragontreasure.h"

DragonTreasure::DragonTreasure()
{
    setType(Utility::Type::DragonTreasure);
}

char DragonTreasure::draw()
{
    return 'G';
}