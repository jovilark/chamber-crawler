#include "../Headers/controller.h"
#include "../Headers/door.h"
#include "../Headers/drow.h"
#include "../Headers/floor.h"
#include "../Headers/goblin.h"
#include "../Headers/hwall.h"
#include "../Headers/none.h"
#include "../Headers/passage.h"
#include "../Headers/shade.h"
#include "../Headers/troll.h"
#include "../Headers/vampire.h"
#include "../Headers/vwall.h"
#include <iostream>
#include <sstream>

using std::getline;
using std::ifstream;
using std::make_unique;
using std::stringstream;

Controller::Controller()
    : m_model{make_unique<Model>()}, text_view{make_unique<TextView>()} {}

void Controller::parseLayout(string file) {
  ifstream inFile(file);
  string line;
  if (inFile.is_open()) {
    while (getline(inFile, line)) {
      for (char c : line)
        switch (c) {
        case '.':
          m_model->generateTile<Floor>();
          break;
        case '#':
          m_model->generateTile<Passage>();
          break;
        case '+':
          m_model->generateTile<Door>();
          break;
        case '-':
          m_model->generateTile<HWall>();
          break;
        case '|':
          m_model->generateTile<VWall>();
          break;
        default:
          m_model->generateTile<None>();
        }
    }
    inFile.close();
  }
}

void Controller::parseNewGame(char c) {
  m_model->generateChambers();
  switch (c) {
  case 's':
    m_model->generatePlayer<Shade>();
    break;
  case 'd':
    m_model->generatePlayer<Drow>();
    break;
  case 'v':
    m_model->generatePlayer<Vampire>();
    break;
  case 't':
    m_model->generatePlayer<Troll>();
    break;
  case 'g':
    m_model->generatePlayer<Goblin>();
    break;
  default:
    m_model->generatePlayer<Shade>();
    break;
  }
  m_model->generateTreasure(10);
  m_model->generatePotions(10);
  m_model->generateEnemies(20);
  text_view->render(m_model.get());
  m_model->resetTurnDesc();
}

void Controller::parseTurn(string cmd) {
  stringstream ss{cmd};
  string arg;
  ss >> arg;

  // If arg is not one letter, interpret it as a direction.
  if (arg.size() > 1) {
    m_model->playerMove(Utility::strToDirection(arg));
  } else {
    switch (arg.front()) {
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
  m_model->enemyTurn();
  // m_model->enemyAttack();
  text_view->render(m_model.get());
  m_model->resetTurnDesc();
}