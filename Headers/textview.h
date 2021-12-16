#ifndef _TEXTVIEW_H_
#define _TEXTVIEW_H_

#include "view.h"

class TextView : public View {
public:
  void render(Model *m);
  void displayScreen(string screen) override;
  void displayFinalScore(int score) override;
};

#endif // _TEXTVIEW_H_
