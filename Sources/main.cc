#include "../Headers/controller.h"
#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main(int argc, char *argv[])
{
    Controller controller{};
    if (argc > 1) controller.parseLayout(string(argv[1]));
    
    cout << "Enter your Type:" << endl;
    char c;
    cin >> c;
    controller.parseNewGame(c);
    
    string cmd;
    while (getline(cin, cmd))
    {
        controller.parseTurn(cmd);
    }
}