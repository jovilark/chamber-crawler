#include "../Headers/merchanttreasure.h"

MerchantTreasure::MerchantTreasure() {
  setType(Utility::Type::MerchantTreasure);
}

bool MerchantTreasure::permeable() { return true; }

char MerchantTreasure::draw() { return 'G'; }

Utility::Effect MerchantTreasure::collected() { return Utility::Effect::MerchantTreasure; }