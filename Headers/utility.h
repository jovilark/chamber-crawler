#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <utility>
#include <string>

using std::pair;
using std::string;

namespace Utility
{
    using Loc = pair<int, int>;

    enum class Direction
    {
        NW=0,
        N=1,
        NE=2,
        E=3,
        SE=4,
        S=5,
        SW=6,
        W=7,
        None=8
    };

    enum class Effect
    {  
        Atk=0,
        Def=1,
        Score=2,
        None=3
    };

    enum class Race
    {
        Shade=0,
        Drow=1,
        Vampire=2,
        Troll=3,
        Goblin=4,
        Human=5,
        Dwarf=6,
        Elf=7,
        Orcs=8,
        Merchant=9,
        Halfling=10
    };

    enum class Terrain
    {
        Floor=0,
        Passage=1,
        Door=2,
        HWall=3,
        VWall=4,
        None=5
    };
    
    Direction strToDirection(string s);
    Race charToRace(char c);
    Terrain charToTerrain(char c);
    Loc addDirectionToLoc(Direction d, Loc l);
};

#endif // _UTILITY_H_