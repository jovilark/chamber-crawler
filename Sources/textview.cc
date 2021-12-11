#include "../Headers/textview.h"
#include <iostream>

using std::cout;
using std::endl;

void TextView::render(State &s) {
  int count{};
  for (auto &x : s) {
    if (x.second)
      cout << x.second->draw();
    else
      cout << x.first->draw();

    ++count;
    if (count == BOARD_WIDTH) {
      cout << endl;
      count = 0;
    }
  }
}