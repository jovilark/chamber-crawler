#ifndef _FLOOR_H_
#define _FLOOR_H_

class Floor : public Tile {
public:
  bool permeable() { return true; }
  char draw() { return '.'; }
};

#endif // _FLOOR_H_