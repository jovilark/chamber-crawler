#include "../Headers/chamber.h"
using std::vector;

int getFirst(Loc l) { return l.first; }
int getSecond(Loc l) { return l.second; }

Chamber::Chamber(vector<Loc> vertices) : vertices{vertices} {
  std::transform(vertices.begin(), vertices.end(), std::back_inserter(x_coords),
                 getFirst);
  std::transform(vertices.begin(), vertices.end(), std::back_inserter(y_coords),
                 getSecond);
  upper_bound = std::make_pair(*max_element(x_coords.begin(), x_coords.end()),
                               *max_element(y_coords.begin(), y_coords.end()));
  lower_bound = std::make_pair(*min_element(x_coords.begin(), x_coords.end()),
                               *min_element(y_coords.begin(), y_coords.end()));
}

bool Chamber::inChamber(Loc point) {
  int hit_edges = 0;
  for (vector<Loc>::iterator x = vertices.begin(); x != vertices.end(); ++x) {
    Loc point1, point2;
    point1 = *x;
    if (x + 1 != vertices.end()) {
      point2 = *(x + 1);
    } else {
      point2 = *vertices.begin();
    }
    if (point1.first > point.first) {
      if ((point.second > point2.second && point.second < point1.second) ||
          (point.second < point2.second && point.second > point1.second)) {
        hit_edges++;
      }
    }
    if (((point1.first <= point.first && point2.first >= point.first) ||
         (point1.first >= point.first && point2.first <= point.first)) &&
        point1.second == point.second && point2.second == point.second) {
      hit_edges++;
    }
  }
  return hit_edges % 2;
}