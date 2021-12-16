#include "../Headers/controller.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

int main(int argc, char *argv[])
{
  srand((unsigned int)time(NULL));
  while (true)
  {
    auto controller = std::make_unique<Controller>();
    if (argc > 1)
      controller->parseLayout(string(argv[1]));
    else
      controller->parseLayout("defaultlayout.txt");

    controller->parseNewGame();
    if (controller->quit())
      break;
    controller->restartGame();
    char c;
    std::cin >> c;
    if (c == 'Y' || c == 'y')
    {
      controller.reset();
      controller = std::make_unique<Controller>();
    }
    else
      break;
  }
}