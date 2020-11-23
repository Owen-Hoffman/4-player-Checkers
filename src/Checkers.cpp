/*************************************************************************
 * File Name:       Checkers.cpp
 * Course:          CPTR 142
 * Copyright (c) 2020-present, CPTR 245
 * All rights reserved
 */

#include <stdexcept>
#include "Checkers.h"
#include "Gameboard.h"
using namespace std;

Checkers::Checkers(int row, int column, Player* owner) { // for initializing the board
    this->row = row;
    this->column = column;
    this->owner = owner;
}

void Checkers::setPiece(int row, int column) {
    this->row = row;
    this->column = column;
}
