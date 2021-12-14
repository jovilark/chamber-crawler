#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "model.h"
#include "textview.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

using std::string;
using std::unique_ptr;

class Controller {
public:
  Controller();
  ~Controller() = default;
  void parseLayout(string file);
  void parseNewGame(char c);
  void parseTurn(string cmd);

private:
  unique_ptr<Model> m_model;
  unique_ptr<TextView> text_view;
};

#endif // _CONTROLLER_H_