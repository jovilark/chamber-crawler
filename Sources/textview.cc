#include "../Headers/textview.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

void TextView::render(Model *m) {
  int count{};
  for (auto &x : m->state()) {
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
  cout << "Race: " << Utility::typeToString(m->getPlayer()->getType())
       << " Gold: " << m->getScore() << endl;
  cout << "HP: " << m->getPlayer()->getHp() << endl;
    cout << "Atk: " << m->getPlayer()->getCurrentAtk() << endl;
  cout << "Def: " << m->getPlayer()->getCurrentDef() << endl;
  cout << "Action: " << m->getTurnDesc() << endl;
}

void TextView::displayScreen(string screen) {
  std::ifstream f(screen);
  if (f.is_open())
    std::cout << f.rdbuf();
}

void TextView::displayFinalScore(int score) {
  std::cout << "\nYOUR FINAL SCORE IS: " << score << std::endl;
}