#ifndef _VIEW_H_
#define _VIEW_H_

#include "model.h"
#include <memory>
#include <vector>

using std::pair;

static const int BOARD_WIDTH = 79;
static const int BOARD_HEIGHT = 30;

class View {
public:
  View();
  virtual ~View() = 0;
  virtual void render(Model *m) = 0;
  virtual void displayScreen(string screen) = 0;
  virtual void displayFinalScore(int score) = 0;
};

#endif // _VIEW_H_
