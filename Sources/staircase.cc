#include "../Headers/staircase.h"

Staircase::Staircase() {
    setType(Utility::Type::Staircase);
}

Utility::Effect Staircase::collected() { return Utility::Effect::Staircase; }