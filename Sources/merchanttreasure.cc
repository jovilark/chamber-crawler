#include "../Headers/merchanttreasure.h"

MerchantTreasure::MerchantTreasure()
{
    setType(Utility::Type::MerchantTreasure);
}

char MerchantTreasure::draw()
{
    return 'G';
}