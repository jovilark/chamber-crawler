#include "../Headers/normaltreasure.h"

NormalTreasure::NormalTreasure()
{
    setType(Utility::Type::NormalTreasure);
}

char NormalTreasure::draw()
{
    return 'G';
}