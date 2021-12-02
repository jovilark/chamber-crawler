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
        None=0,
        SmallTreasure=1,
        NormalTreasure=2,
        MerchantTreasure=3,
        DragonTreasure=4,
        AtkUp=5,
        AtkDown=6,
        DefUp=7,
        DefDown=8
    };

    enum class Type
    {
        None=0,
        SmallTreasure=1,
        NormalTreasure=2,
        MerchantTreasure=3,
        DragonTreasure=4,
        Shade=5,
        Dwarf=6
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
    Type charToType(char c);
    Terrain charToTerrain(char c);
    Loc addDirectionToLoc(Direction d, Loc l);
    string typeToString(Type t);
};

#endif // _UTILITY_H_