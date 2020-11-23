/*************************************************************************
 * File Name:       Checkers.h
 * Course:          CPTR 142
 * Copyright (c) 2020-present, CPTR 245
 * All rights reserved
 */
#ifndef SRC_CHECKERS_H
#define SRC_CHECKERS_H
#include "Gameboard.h"
#include "Player.h"

class Checkers {
    public:
        Checkers(int row, int column, Player* owner);
        int getRow() { return row; }
        int getColumn() { return column; }
        void setPiece(int row, int column);
        Player* getOwner() { return owner; }
        virtual char getSymbol() { return owner->getSymbol(); }
    protected:
        int row;
        int column;
        Player* owner;

};

#endif  // SRC_CHECKERS_H_
