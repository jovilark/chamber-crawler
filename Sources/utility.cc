#include "../Headers/utility.h"

using namespace Utility;

Direction Utility::strToDirection(string s) {
  if (s == "nw")
    return Direction::NW;
  else if (s == "no")
    return Direction::N;
  else if (s == "ne")
    return Direction::NE;
  else if (s == "ea")
    return Direction::E;
  else if (s == "se")
    return Direction::SE;
  else if (s == "so")
    return Direction::S;
  else if (s == "sw")
    return Direction::SW;
  else if (s == "we")
    return Direction::W;
  else
    return Direction::None;
}

Type Utility::charToType(char c) {
  switch (c) {
  case 's':
    return Type::Shade;
  case 'd':
    return Type::Drow;
  case 'v':
    return Type::Vampire;
  case 't':
    return Type::Troll;
  case 'g':
    return Type::Goblin;
  default:
    return Type::None;
  }
}

Terrain Utility::charToTerrain(char c) {
  switch (c) {
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

Loc Utility::addDirectionToLoc(Direction d, Loc l) {
  switch (d) {
  case Direction::NW:
    l.first -= 1;
    l.second -= 1;
    break;
  case Direction::N:
    l.second -= 1;
    break;
  case Direction::NE:
    l.first += 1;
    l.second -= 1;
    break;
  case Direction::E:
    l.first += 1;
    break;
  case Direction::SE:
    l.first += 1;
    l.second += 1;
    break;
  case Direction::S:
    l.second += 1;
    break;
  case Direction::SW:
    l.first -= 1;
    l.second += 1;
    break;
  case Direction::W:
    l.first -= 1;
    break;
  default:
    break;
  }
  return l;
}

string Utility::typeToString(Type t) {
  switch (t) {
  case Type::Shade:
    return "Shade";
  case Type::Drow:
    return "Drow";
  case Type::Vampire:
    return "Vampire";
  case Type::Troll:
    return "Troll";
  case Type::Goblin:
    return "Goblin";
  case Type::Human:
    return "Human";
  case Type::Dwarf:
    return "Dwarf";
  case Type::Elf:
    return "Elf";
  case Type::Orc:
    return "Orc";
  case Type::Merchant:
    return "Merchant";
  case Type::Halfling:
    return "Halfling";
  case Type::Dragon:
    return "Dragon";
  case Type::SmallTreasure:
    return "Small Treasure";
  case Type::NormalTreasure:
    return "Normal Treasure";
  case Type::MerchantTreasure:
    return "Merchant Treasure";
  case Type::DragonTreasure:
    return "Dragon Treasure";
  case Type::AtkUpPotion:
    return "BA";
  case Type::AtkDownPotion:
    return "WA";
  case Type::DefUpPotion:
    return "BD";
  case Type::DefDownPotion:
    return "WD";
  case Type::HpUpPotion:
    return "RH";
  case Type::HpDownPotion:
    return "PH";
  case Type::Staircase:
    return "Staircase";
  default:
    return "None";
  }
}

string Utility::dirToString(Direction d) {
  switch (d) {
  case Direction::NW:
    return "Northwest";
  case Direction::N:
    return "North";
  case Direction::NE:
    return "Northeast";
  case Direction::E:
    return "East";
  case Direction::SE:
    return "Southeast";
  case Direction::S:
    return "South";
  case Direction::SW:
    return "Southwest";
  case Direction::W:
    return "West";
  default:
    return "None";
  }
}

bool Utility::isPlayableCharacter(Type t) { return (int)t >= 0 && (int)t <= 4; }

bool Utility::isCharacter(Type t) { return (int)t >= 0 && (int)t <= 11; }

bool Utility::isEnemy(Type t) { return (int)t >= 5 && (int)t <= 11; }

bool Utility::isPotion(Type t) { return (int)t >= 16 && (int)t <= 21; }

bool Utility::isTreasure(Type t) { return (int)t >= 12 && (int)t <= 15; }

bool Utility::isItem(Type t) { return (int)t >= 12 && (int)t <= 22; }