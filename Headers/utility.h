#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <string>
#include <utility>

using std::pair;
using std::string;

namespace Utility {
using Loc = pair<int, int>;

enum class Direction {
  NW = 0,
  N = 1,
  NE = 2,
  E = 3,
  SE = 4,
  S = 5,
  SW = 6,
  W = 7,
  None = 8
};

enum class Effect {
  None = 0,
  SmallTreasure = 1,
  NormalTreasure = 2,
  MerchantTreasure = 3,
  DragonTreasure = 4,
  AtkUp = 5,
  AtkDown = 6,
  DefUp = 7,
  DefDown = 8,
  HpUp = 9,
  HpDown = 10,
  Staircase = 11,
  TrollHealing = 12
};

enum class Type {
  Shade = 0,
  Drow = 1,
  Vampire = 2,
  Troll = 3,
  Goblin = 4,
  Human = 5,
  Dwarf = 6,
  Elf = 7,
  Orc = 8,
  Merchant = 9,
  Halfling = 10,
  Dragon = 11,
  SmallTreasure = 12,
  NormalTreasure = 13,
  MerchantTreasure = 14,
  DragonTreasure = 15,
  AtkUpPotion = 16,
  AtkDownPotion = 17,
  DefUpPotion = 18,
  DefDownPotion = 19,
  HpUpPotion = 20,
  HpDownPotion = 21,
  Staircase = 22,
  None = 23
};

enum class Terrain {
  Floor = 0,
  Passage = 1,
  Door = 2,
  HWall = 3,
  VWall = 4,
  None = 5
};

Direction strToDirection(string s);
Type charToType(char c);
Terrain charToTerrain(char c);
Loc addDirectionToLoc(Direction d, Loc l);
string typeToString(Type t);
string dirToString(Direction d);
bool isPlayableCharacter(Type t);
bool isCharacter(Type t);
bool isEnemy(Type t);
bool isPotion(Type t);
bool isTreasure(Type t);
bool isItem(Type t);
}; // namespace Utility

#endif // _UTILITY_H_