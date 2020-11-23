#include "Checkers.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#ifndef PLAYER_H_
#define PLAYER_H_

class Checkers;

class Player {
public:
  Player(string name, char symbol, int team);
  void setName(string newName);
  string getName() { return name; }
  char getSymbol() { return symbol; }
  int getTeam() { return team; }

private:
  string name;
  char symbol;
  int team;
};

#endif