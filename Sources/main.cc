#include "../Headers/controller.h"
#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    Controller controller{};
    if (argc > 1) controller.parseLayout(string(argv[1]));
    
    cout << "Enter your race:" << endl;
    char c;
    cin >> c;
    controller.parseNewGame(c);
    
    // TODO: Enable this once moving, attacking, using works.
    /*
    string cmd;
    while (cin >> cmd)
    {
        controller.parseTurn(cmd);
    }
    */
}