/*************************************************************************
 * File Name:       Gameboard.h
 * Course:          CPTR 142
 * Copyright (c) 2020-present, CPTR 245
 * All rights reserved
 */
#ifndef SRC_GAMEBOARD_H_
#define SRC_GAMEBOARD_H_

#include "Checkers.h"
#include "Player.h"

class Gameboard {
  public:
    Gameboard();
    void drawBoard();
    void movePiece(Player* owner);
    void choosePiece(Checkers* piece, Player* owner, int row, int column);
    void movePiece(Checkers* piece, Player* owner, int row, int column);

    void removePiece(Player *owner);
    void inputError(int error);
    void t1Move(Player *owner);
    void t2Move(Player *owner);
    void jump(Player *owner);

    void setCheckers();
    bool checkWin();
    void displayWin();

  private:
  bool flag;
  int numPieces;
  int rowNum;
  int colNum;
  int newColNum;
  int newRowNum;
  int realNewRowNum;
  int realNewColNum;
    // Checkers* board[8][8];
    char board[8][8];
};

#endif  // SRC_GAMEBOARD_H_
