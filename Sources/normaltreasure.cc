#include "../Headers/normaltreasure.h"

NormalTreasure::NormalTreasure() { setType(Utility::Type::NormalTreasure); }

bool NormalTreasure::permeable() { return true; }

char NormalTreasure::draw() { return 'G'; }