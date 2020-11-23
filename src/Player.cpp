#include <string>
using namespace std;

#include "Player.h"

Player::Player(string name, char symbol, int team) {
  this->name = name;
  this->symbol = symbol;
  this->team = team;
}

void Player::setName(string newName) {
  name = newName;
  return;
}
