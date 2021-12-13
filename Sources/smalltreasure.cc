#include "../Headers/smalltreasure.h"

SmallTreasure::SmallTreasure() { setType(Utility::Type::SmallTreasure); }

bool SmallTreasure::permeable() { return true; }

char SmallTreasure::draw() { return 'G'; }

Utility::Effect SmallTreasure::collected() { return Utility::Effect::SmallTreasure; }