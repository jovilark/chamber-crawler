#include "../Headers/controller.h"
#include <sstream>

using std::make_unique;
using std::ifstream;
using std::getline;
using std::stringstream;

void Controller::parseLayout(string file)
{
    ifstream inFile(file);
    string line;
    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            for (char c : line) m_model->generateTile(Utility::charToTerrain(c));
        }
        inFile.close();
    }
}

void Controller::parseNewGame(char c)
{
    m_model->generatePlayer(Utility::charToRace(c));
    m_model->render();
}

void Controller::parseTurn(string cmd)
{
    stringstream ss{cmd};
    string arg;
    ss >> arg;

    // If arg is not one letter, try to cast it as a direction.
    if (arg.size() > 1) 
    {
        m_model->playerMove(Utility::strToDirection(arg));
        return;
    }

    switch (arg.front())
    {
        case 'f':
            m_model->setEnemyMovement(false);
            break;
        case 'r':
            m_model->restart();
            break;
        case 'q':
            m_model->quit();
            break;
        case 'u':
            ss >> arg;
            m_model->playerUse(Utility::strToDirection(arg));
            break;
        case 'a':
            ss >> arg;
            m_model->playerAttack(Utility::strToDirection(arg));
        default:
            break;
    }
}