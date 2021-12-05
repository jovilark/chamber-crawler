#include "../Headers/controller.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

int main(int argc, char *argv[]) {
  srand((unsigned int)time(NULL));
  Controller controller{};
  if (argc > 1)
    controller.parseLayout(string(argv[1]));

  string cmd;
  cout << "Enter your Type:" << endl;

  getline(cin, cmd);
  controller.parseNewGame(cmd[0]);

  while (getline(cin, cmd)) {
    controller.parseTurn(cmd);
  }
}