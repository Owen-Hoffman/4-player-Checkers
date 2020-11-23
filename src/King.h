/*************************************************************************
 * File Name:       King.h
 * Course:          CPTR 142
 * Copyright (c) 2020-present, CPTR 245
 * All rights reserved
 */
#ifndef SRC_KING_H_
#define SRC_KING_H_
#include <cctype> // for toupper
#include "Checkers.h"

class King : public Checkers {
    public:
        char getSymbol() { return toupper(owner->getSymbol()); }
};

#endif  // SRC_KING_H_
