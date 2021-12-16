#include "../Headers/model.h"
#include "../Headers/atkdownpotion.h"
#include "../Headers/atkuppotion.h"
#include "../Headers/chamber.h"
#include "../Headers/defdownpotion.h"
#include "../Headers/defuppotion.h"
#include "../Headers/door.h"
#include "../Headers/dragon.h"
#include "../Headers/dragontreasure.h"
#include "../Headers/drow.h"
#include "../Headers/dwarf.h"
#include "../Headers/elf.h"
#include "../Headers/floor.h"
#include "../Headers/goblin.h"
#include "../Headers/halfling.h"
#include "../Headers/hpdownpotion.h"
#include "../Headers/hpuppotion.h"
#include "../Headers/human.h"
#include "../Headers/hwall.h"
#include "../Headers/merchant.h"
#include "../Headers/none.h"
#include "../Headers/normaltreasure.h"
#include "../Headers/orc.h"
#include "../Headers/passage.h"
#include "../Headers/shade.h"
#include "../Headers/smalltreasure.h"
#include "../Headers/staircase.h"
#include "../Headers/textview.h"
#include "../Headers/troll.h"
#include "../Headers/vampire.h"
#include "../Headers/vwall.h"

using std::cout;
using std::endl;
using std::make_unique;

Model::Model()
    : m_player{nullptr}, m_playerLoc{make_pair(-1, -1)}, m_move{true},
      turn_desc{""}, m_entities{}, m_tiles{}, m_floor{0},
      m_merchantHostile{0}, m_potions{}, m_dragons{} {}

void Model::generateChambers() {
  Chamber chamber1 = vector<Loc>{Loc(2, 2), Loc(29, 2), Loc(29, 7), Loc(2, 7)};
  Chamber chamber2 = vector<Loc>{
      Loc(38, 2), Loc(62, 2), Loc(62, 4),  Loc(70, 4),  Loc(70, 5), Loc(73, 5),
      Loc(73, 6), Loc(76, 6), Loc(76, 13), Loc(60, 13), Loc(60, 7), Loc(38, 7)};
  Chamber chamber3 =
      vector<Loc>{Loc(37, 9), Loc(50, 9), Loc(50, 13), Loc(37, 13)};
  Chamber chamber4 =
      vector<Loc>{Loc(3, 14), Loc(25, 14), Loc(25, 22), Loc(3, 22)};
  Chamber chamber5 = vector<Loc>{Loc(76, 15), Loc(76, 22), Loc(36, 22),
                                 Loc(36, 18), Loc(64, 18), Loc(64, 15)};
  m_chambers.push_back(chamber1);
  m_chambers.push_back(chamber2);
  m_chambers.push_back(chamber3);
  m_chambers.push_back(chamber4);
  m_chambers.push_back(chamber5);
}

Loc Model::LocInChamber(int chamber_num) {
  Loc l = NEEDS_RANDOM;
  while (!m_chambers[chamber_num].inChamber(l)) {
    l = make_pair(rand() % (m_chambers[chamber_num].upper_bound.first -
                            m_chambers[chamber_num].lower_bound.first - 1) +
                      m_chambers[chamber_num].lower_bound.first + 1,
                  rand() % (m_chambers[chamber_num].upper_bound.second -
                            m_chambers[chamber_num].lower_bound.second - 1) +
                      m_chambers[chamber_num].lower_bound.second + 1);
  }
  return l;
}

void Model::generateEnemies(int n) {
  for (int i = 0; i < n; i++) {
    int rand_num = rand() % 18;
    if (rand_num < 4) {
      generateEntity<Human>();
    } else if (rand_num >= 4 && rand_num < 7) {
      generateEntity<Dwarf>();
    } else if (rand_num >= 7 && rand_num < 12) {
      generateEntity<Halfling>();
    } else if (rand_num >= 12 && rand_num < 14) {
      generateEntity<Elf>();
    } else if (rand_num >= 14 && rand_num < 16) {
      generateEntity<Orc>();
    } else {
      generateEntity<Merchant>();
      m_entities.back()->setHostile(m_merchantHostile);
    }
  }
}

void Model::generateTreasure(int n) {
  for (int i = 0; i < n; i++) {
    int rand_num = rand() % 8;
    if (rand_num < 5) {
      generateEntity<NormalTreasure>();
    } else if (rand_num >= 5 && rand_num < 6) {
      generateEntity<SmallTreasure>();
    } else {
      Loc dragon_treasure = generateEntity<DragonTreasure>();
      generateDragon(dragon_treasure);
    }
  }
}

void Model::generateDragon(Loc dragon_treasure) {
  Direction dir = (Direction)(rand() % 8);
  Entity *horde = m_entities.back().get();

  auto &target =
      m_state[indiceFromLoc(addDirectionToLoc(dir, dragon_treasure))];

  while (target.second || !target.first->permeable()) {
    dir = (Direction)(rand() % 8);
    target = m_state[indiceFromLoc(addDirectionToLoc(dir, dragon_treasure))];
  }

  m_dragons[horde] =
      generateEntity<Dragon>(addDirectionToLoc(dir, dragon_treasure),
                             m_entities.back()->getChamberNum());
}

void Model::generatePotions(int n) {
  for (int i = 0; i < n; i++) {
    int rand_num = rand() % 6;
    switch (rand_num) {
    case 0:
      generateEntity<AtkUpPotion>();
      break;
    case 1:
      generateEntity<AtkDownPotion>();
      break;
    case 2:
      generateEntity<DefUpPotion>();
      break;
    case 3:
      generateEntity<DefDownPotion>();
      break;
    case 4:
      generateEntity<HpUpPotion>();
      break;
    default:
      generateEntity<HpDownPotion>();
    }
  }
}

bool Model::playerMove(Direction d) {
  Loc l = addDirectionToLoc(d, m_playerLoc);
  auto &target = m_state[indiceFromLoc(l)];
  auto &origin = m_state[indiceFromLoc(m_playerLoc)];

  bool result = move(origin, target);
  if (result) {
    m_playerLoc = l;
    printMove(d);
  }

  finished();
  return result;
}

void Model::finished() { parseEffect(m_player->finished()); }

void Model::enemyTurn(bool canMove) {
  unordered_map<Entity *, bool> moved;
  for (int dX = -1; dX < 2; ++dX) {
    for (int dY = -1; dY < 2; ++dY) {
      if (dX == 0 && dY == 0)
        continue;

      Loc l{m_playerLoc.first + dX, m_playerLoc.second + dY};
      auto &attacker = m_state[indiceFromLoc(l)];
      if (!attacker.second)
        continue;
      auto &target = m_state[indiceFromLoc(m_playerLoc)];
      moved[attacker.second] = true;
      bool hit = rand() % 2;
      if (hit) {
        attack(attacker, target);
      }
    }
  }

  if (!canMove)
    return;

  for (size_t i = 0; i < m_state.size(); ++i) {
    auto &origin = m_state[i];
    if (!origin.second || moved[origin.second] || origin.second == m_player)
      continue;

    Direction d = origin.second->move();

    int x = i % BOARD_WIDTH;
    int y = i / BOARD_WIDTH;
    Loc l = make_pair(x, y);
    l = addDirectionToLoc(d, l);

    auto &target = m_state[indiceFromLoc(l)];
    if (m_chambers[origin.second->getChamberNum()].inChamber(l)) {
      moved[origin.second] = move(origin, target);
    }
  }
}

bool Model::playerUse(Direction d) {
  Loc l = addDirectionToLoc(d, m_playerLoc);
  auto &target = m_state[indiceFromLoc(l)];

  finished();
  return interact(target);
}

// Returns true if an enemy was killed, false otherwise.
// Attempts to attack an enemy in the direction.
bool Model::playerAttack(Direction d) {
  Loc l = addDirectionToLoc(d, m_playerLoc);
  auto &attacker = m_state[indiceFromLoc(m_playerLoc)];
  auto &target = m_state[indiceFromLoc(l)];

  finished();
  return attack(attacker, target);
}

bool Model::collect(Node &target) {
  if (!target.second)
    return false;
  bool result = parseEffect(target.second->collected());
  if (result) {
    removeEntity(target.second);
    target.second = nullptr;
  }
  return result;
}

bool Model::interact(Node &target) {
  if (!target.second)
    return false;
  bool result = parseEffect(target.second->interacted());
  if (result) {
    m_potions[target.second->getType()] = true;
    removeEntity(target.second);
    target.second = nullptr;
  }
  return result;
}

int Model::indiceFromLoc(Loc l) { return l.first + l.second * BOARD_WIDTH; }

bool Model::move(Node &origin, Node &target) {
  if (!target.first->permeable())
    return false;
  if (target.second) {
    if (!target.second->permeable() || origin.second != m_player)
      return false;
    else if (origin.second == m_player)
      collect(target);
  }
  target.second = origin.second;
  origin.second = nullptr;
  return true;
}

bool Model::attack(Node &attacker, Node &target) {
  if (!attacker.second)
    return false;
  if (!target.second)
    return false;
  if (attacker.second->getType() == Type::DragonTreasure) {
    return attack(m_state[indiceFromLoc(m_dragons[attacker.second])], target);
  }
  if (!attacker.second->getHostile())
    return false;
  if (target.second->getType() == Type::Merchant)
    m_merchantHostile = true;
  int oldHp = target.second->getHp();
  int hp = attacker.second->attack(target.second);
  printAttack(attacker.second, target.second, oldHp - hp);
  bool died = hp <= 0;
  if (died) {
    if (target.second->getType() == Type::Dragon) {
      // make dragon horde permeable
    }
  }
  if (target.second != m_player) {
    parseEffect(target.second->died());
    removeEntity(target.second);
    target.second = nullptr;
  }
  if (attacker.second == m_player && m_player->getType() == Type::Troll)
    m_player->setGold(m_player->getGold() + 5);

  return died;
}

void Model::removeEntity(Entity *e) {
  for (size_t i = 0; i < m_entities.size(); ++i) {
    auto &x = m_entities[i];
    if (x.get() == e) {
      m_entities.erase(m_entities.begin() + i);
      return;
    }
  }
}

void Model::printAttack(Entity *attacker, Entity *defender, int damage) {
  if (attacker == m_player)
    turn_desc += "PC";
  else
    turn_desc += typeToString(attacker->getType());
  turn_desc += " deals " + std::to_string(damage) + " damage to ";
  if (defender == m_player)
    turn_desc += "PC. ";
  else
    turn_desc += typeToString(defender->getType()) + " (" +
                 std::to_string(defender->getHp()) + " HP). ";
}

void Model::printMove(Direction d) {
  turn_desc += "PC moves " + dirToString(d);

  vector<Type> nearby{scout()};

  if (!nearby.empty())
    turn_desc += " and sees";
  else
    turn_desc += ". ";

  for (size_t i = 0; i < nearby.size(); ++i) {
    turn_desc += " ";
    if (isPotion(nearby[i]) && !m_potions[nearby[i]])
      turn_desc += "Potion";
    else
      turn_desc += typeToString(nearby[i]);
    if (i != nearby.size() - 1)
      turn_desc += ",";
    else
      turn_desc += ". ";
  }
}

vector<Type> Model::scout() {
  vector<Type> result{};
  for (int dX = -1; dX < 2; ++dX) {
    for (int dY = -1; dY < 2; ++dY) {
      if (dX == 0 && dY == 0)
        continue;

      Loc l{m_playerLoc.first + dX, m_playerLoc.second + dY};
      auto &target = m_state[indiceFromLoc(l)];

      if (target.second) {
        Type t = target.second->getType();
        if (isCharacter(t))
          continue;
        result.push_back(t);
      }
    }
  }
  return result;
}

void Model::resetEntities() {
  if (m_floor != 0) {
    m_entities.erase(m_entities.begin() + 1, m_entities.end());
    for (auto &i : m_state)
      i.second = nullptr;
    m_player->setChamberNum(rand() % 5);
    Loc l = LocInChamber(m_player->getChamberNum());
    m_state[indiceFromLoc(l)].second = m_player;
    m_playerLoc = l;
    m_player->setAtkBonus(0);
    m_player->setDefBonus(0);
  }
}

int Model::getNonPlayerChamber() {
  int chamber = rand() % 5;
  while (chamber == m_player->getChamberNum()) {
    chamber = rand() % 5;
  }
  return chamber;
}

bool Model::parseEffect(Effect e) {
  float multi = 1;
  if (m_player->getType() == Type::Drow)
    multi += 0.5;

  switch (e) {
  case Effect::SmallTreasure:
    m_player->setGold(m_player->getGold() + 1);
    break;
  case Effect::NormalTreasure:
    m_player->setGold(m_player->getGold() + 2);
    break;
  case Effect::MerchantTreasure:
    m_player->setGold(m_player->getGold() + 4);
    break;
  case Effect::DragonTreasure:
    m_player->setGold(m_player->getGold() + 6);
    break;
  case Effect::AtkUp:
    m_player->setAtkBonus(m_player->getAtkBonus() + 5 * multi);
    break;
  case Effect::AtkDown:
    m_player->setAtkBonus(m_player->getAtkBonus() - 5 * multi);
    break;
  case Effect::DefUp:
    m_player->setDefBonus(m_player->getDefBonus() + 5 * multi);
    break;
  case Effect::DefDown:
    m_player->setDefBonus(m_player->getDefBonus() - 5 * multi);
    break;
  case Effect::HpUp:
    m_player->setHp(m_player->getHp() + 10 * multi);
    break;
  case Effect::HpDown:
    m_player->setHp(m_player->getHp() - 10 * multi);
    break;
  case Effect::Staircase:
    setNextFloor(true);
    break;
  case Effect::TrollHealing:
    m_player->setHp(m_player->getHp() + 5);
  default:
    return false;
  }
  return true;
}

void Model::generateLevel() {
  resetEntities();
  generateEntity<Staircase>(NEEDS_RANDOM, getNonPlayerChamber());
  generateTreasure(10 - present_treasure);
  generatePotions(10 - present_potions);
  generateEnemies(20 - present_enemies);
  resetTurnDesc();
}