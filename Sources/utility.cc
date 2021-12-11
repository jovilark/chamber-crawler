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
  case Type::Dwarf:
    return "Dwarf";
  default:
    return "None";
  }
}