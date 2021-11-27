#include "../Headers/utility.h"

using namespace Utility;

Direction Utility::strToDirection(string s)
{
    if (s == "nw") return Direction::NW;
    else if (s == "no") return Direction::N;
    else if (s == "ne") return Direction::NE;
    else if (s == "ea") return Direction::E;
    else if (s == "se") return Direction::SE;
    else if (s == "sw") return Direction::SW;
    else if (s == "we") return Direction::W;
    else return Direction::None;
}

Race Utility::charToRace(char c)
{
    switch (c)
    {
        case 'S':
            return Race::Shade;
        default:
            return Race::Shade;
    }
}

Terrain Utility::charToTerrain(char c)
{
    switch (c)
    {
        case '.':
            return Terrain::Floor;
        case '#':
            return Terrain::Passage;
        case '+':
            return Terrain::Door;
        case '-':
            return Terrain::HWall;
        case '|':
            return Terrain::VWall;
        default:
            return Terrain::None;
    }
}