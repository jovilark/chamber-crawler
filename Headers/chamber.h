#ifndef _CHAMBER_H_
#define _CHAMBER_H_

#include "utility.h"
#include <algorithm>
#include <vector>
using Utility::Loc;

class Chamber {
  std::vector<Loc> vertices;
  std::vector<int> x_coords;
  std::vector<int> y_coords;

public:
  Chamber(std::vector<Loc> vertices);
  ~Chamber() = default;
  bool inChamber(Loc point);
  Loc upper_bound;
  Loc lower_bound;
};

#endif // _CHAMBER_H_