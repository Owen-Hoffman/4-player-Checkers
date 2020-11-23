/*************************************************************************
 * File Name:       Gameboard.cpp
 * Course:          CPTR 142
 * Copyright (c) 2020-present, CPTR 245
 * All rights reserved
 */

#include <iostream>
#include <stdexcept>
using namespace std;

#include "Gameboard.h"

void Gameboard::drawBoard() {

  cout << "  ";
  for (int i = 0; i < 8; i++) {
    cout << "    " << i + 1 << "   ";
  }
  cout << endl;

  // Board and Row numbers
  cout << "  +-------+-------+-------+-------+-------+-------+-------+-------+"
       << endl;
  for (int i = 0; i < 8; i++) {
    int j = 0;
    cout
        << "  |       |       |       |       |       |       |       |       |"
        << endl;
    cout << i + 1 << " "
         << "|   " << board[i][j] << "   |   " << board[i][j + 1] << "   |   "
         << board[i][j + 2] << "   |   " << board[i][j + 3] << "   |   "
         << board[i][j + 4] << "   |   " << board[i][j + 5] << "   |   "
         << board[i][j + 6] << "   |   " << board[i][j + 7] << "   |" << endl;
    cout
        << "  |       |       |       |       |       |       |       |       |"
        << endl;
    cout
        << "  +-------+-------+-------+-------+-------+-------+-------+-------+"
        << endl;
  }
}

Gameboard::Gameboard(/*char board[8][8]*/) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (((i + j) % 2 == 0)) {
        board[i][j] = '*';
      } else if (((i + j) % 2 != 0)) {
        board[i][j] = ' ';
      }
      // std::cout << board[i][j];
    }
    // std::cout << std::endl;
  }
}

void Gameboard::inputError(int error) {
  // int error to distinguish between dif error type
  if (error == 1) {
    while (cin.fail()) {
      cout << "Error. You must input an integer" << endl;
      cin.clear();
      cin >> newRowNum;
    }
  } else {
    while (cin.fail()) {
      cout << "Error. You must input an integer" << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cin >> rowNum;
    }
  }
}

void Gameboard::setCheckers() {

  // Team 1
  board[0][0] = 'a';
  board[0][2] = 'a';
  board[0][4] = 'b';
  board[0][6] = 'b';
  board[1][1] = 'a';
  board[1][3] = 'a';
  board[1][5] = 'b';
  board[1][7] = 'b';
  board[2][0] = 'a';
  board[2][2] = 'a';
  board[2][4] = 'b';
  board[2][6] = 'b';

  // Team 2
  // change this
  board[5][1] = 'c';
  board[5][3] = 'c';
  board[5][5] = 'd';
  board[5][7] = 'd';
  board[6][0] = 'c';
  board[6][2] = 'c';
  board[6][4] = 'd';
  board[6][6] = 'd';
  board[7][1] = 'c';
  board[7][3] = 'c';
  board[7][5] = 'd';
  board[7][7] = 'd';
}

void Gameboard::movePiece(Player *owner) {
  Gameboard g;
  numPieces = 0;
  // check if player has any pieces
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((board[i][j] == owner->getSymbol()) ||
          (board[i][j] == toupper(owner->getSymbol()))) {

        numPieces += 1;
      }
    }
  }

  if (numPieces != 0) {
    do {
      flag = true;
      try {
        cout << owner->getName()
             << " Enter the coordinates of the piece you would like to move"
             << endl;
        cout << "Row number: ";
        cin >> rowNum;

        // error check rowNum
        inputError(0);

        cout << "Column number: ";
        cin >> colNum;
        cout << endl;

        // error check colNum
        inputError(0);

        int realRow = rowNum - 1;
        int realColumn = colNum - 1;

        // checks original coordinates for errors
        if (realRow < 0 || realRow > 7 || realColumn < 0 || realColumn > 7) {
          flag = false;
          throw runtime_error("These coordinates are not on the board.");
        } else if (board[realRow][realColumn] == ' ') {
          flag = false;
          throw runtime_error("Invalid square.");
        } else if (tolower(board[realRow][realColumn]) != owner->getSymbol()) {
          flag = false;
          throw runtime_error("This is not your piece");
        }
      } catch (runtime_error &excpt) {
        cout << excpt.what() << endl;
        cout << "Please try again" << endl;
      }
    } while (flag == false);
    // enter new coordinates for error checking
    // asks for coordinates again if there is an error
    do {
      flag = true;
      try {
        cout << "Enter the coordinates of the square you would like to move to"
             << endl;
        cout << "Row Number: ";
        cin >> newRowNum;

        // error check for new row
        inputError(1);

        cout << "Column Number: ";
        cin >> newColNum;
        cout << endl;

        // error check for new column
        inputError(1);

        realNewRowNum = newRowNum - 1;
        realNewColNum = newColNum - 1;

        if (realNewRowNum < 0 || realNewRowNum > 7 || realNewColNum < 0 ||
            realNewColNum > 7) {
          flag = false;
          throw runtime_error("These coordinates are not on the board.");
        } else if (board[realNewRowNum][realNewColNum] == ' ') {
          flag = false;
          throw runtime_error("Invalid square.");
        }

        // check for team

        if (owner->getTeam() == 1) {
          // Team 1 move
          // check for valid move
          // check for backwards movement for non-king pieces
          if (islower(board[rowNum - 1][colNum - 1])) {
            if (newRowNum < rowNum) {
              flag = false;
              throw runtime_error("t1 check for backwards movement for "
                                  "non-king pieces"); // You cannot move
                                                      // backwards
            }
          }
          // check if square is empty and move there
          if (board[newRowNum - 1][newColNum - 1] == '*') {
            if (isupper(board[rowNum - 1][colNum - 1])) {
              board[newRowNum - 1][newColNum - 1] = toupper(owner->getSymbol());
            }
            // check to see if piece is on the back row
            else {
              if ((newRowNum) == (8)) {
                board[realNewRowNum][realNewColNum] =
                    toupper(owner->getSymbol());
              } else {
                board[newRowNum - 1][newColNum - 1] = owner->getSymbol();
              }
            }

            board[rowNum - 1][colNum - 1] = '*';
            return;
          }
          // checking for jumping
          else if ((board[realNewRowNum][realNewColNum] == 'c') |
                   (board[realNewRowNum][realNewColNum] == 'C') |
                   (board[realNewRowNum][realNewColNum] == 'd') |
                   (board[realNewRowNum][realNewColNum] == 'D')) {

            // king jump forward right
            if ((colNum - 1) < realNewColNum) {
              if (isupper(board[rowNum - 1][colNum - 1])) {
                if ((rowNum - 1) < realNewRowNum) {
                  board[rowNum - 1][colNum - 1] = '*';
                  board[realNewRowNum][realNewColNum] = '*';
                  board[realNewRowNum + 1][realNewColNum + 1] =
                      toupper(owner->getSymbol());
                  return;
                }
                // king jump back right
                else if ((rowNum - 1) > realNewRowNum) {
                  board[rowNum - 1][colNum - 1] = '*';
                  board[realNewRowNum][realNewColNum] = '*';
                  board[realNewRowNum - 1][realNewColNum + 1] =
                      toupper(owner->getSymbol());
                  return;
                }
              }

              // normal forward right
              else if (islower(board[rowNum - 1][colNum - 1])) {
                board[rowNum - 1][colNum - 1] = '*';
                board[realNewRowNum][realNewColNum] = '*';
                board[realNewRowNum + 1][realNewColNum + 1] =
                    owner->getSymbol();
                if (((realNewRowNum + 1) + 1) == 8) {
                  board[realNewRowNum + 1][realNewColNum + 1] =
                      toupper(owner->getSymbol());
                }
                return;
              }
            } else if ((colNum - 1) > realNewColNum) {
              cout << "flag 1" << endl;
              // king jump forward left
              if (isupper(board[rowNum - 1][colNum - 1])) {
                if ((rowNum - 1) < realNewRowNum) {
                  board[rowNum - 1][colNum - 1] = '*';
                  board[realNewRowNum][realNewColNum] = '*';
                  board[realNewRowNum + 1][realNewColNum - 1] =
                      toupper(owner->getSymbol());
                  return;
                }
                // king jump backwards left
                else if ((rowNum - 1) > realNewRowNum) {
                  board[rowNum - 1][colNum - 1] = '*';
                  board[realNewRowNum][realNewColNum] = '*';
                  board[realNewRowNum - 1][realNewColNum - 1] =
                      toupper(owner->getSymbol());
                  return;
                }
              }

              // normal jump forwards left
              else if (islower(board[rowNum - 1][colNum - 1])) {
                cout << "flag2";
                board[rowNum - 1][colNum - 1] = '*';
                board[realNewRowNum][realNewColNum] = '*';
                board[realNewRowNum + 1][realNewColNum - 1] =
                    owner->getSymbol();
                if (((realNewRowNum + 1) + 1) == 8) {
                  board[realNewRowNum + 1][realNewColNum - 1] =
                      toupper(owner->getSymbol());
                }
                return;
              }
            }
          }

          if (((board[7][1]) | (board[7][3]) | (board[7][5]) | (board[7][7])) ==
              owner->getSymbol()) {
            if (board[7][1] == owner->getSymbol()) {
              board[7][1] = toupper(owner->getSymbol());
            }
          }

          // Team 2 move
        } else if (owner->getTeam() == 2) {
          // check for valid move
          // check to see if piece moved only 1 space
          if (abs((newRowNum - 1) - (rowNum - 1)) != 1 ||
              abs((newRowNum - 1) - (rowNum - 1)) != 1) {
            flag = false;
            throw runtime_error("t2 check to see if piece moved only 1 space");
          }
          // check for backwards movement for non-king pieces
          if (islower(board[rowNum - 1][colNum - 1])) {
            if (newRowNum > rowNum) {
              flag = false;
              throw runtime_error(
                  "t2 check for backwards movement for non-king pieces");
            }
          }
          // check if square is empty and move there
          if (board[newRowNum - 1][newColNum - 1] == '*') {
            if (isupper(board[rowNum - 1][colNum - 1])) {
              board[newRowNum - 1][newColNum - 1] = toupper(owner->getSymbol());
            } else {
              // check to see if piece is on the back row
              if (newRowNum == 0) {
                board[realNewRowNum][realNewColNum] =
                    toupper(owner->getSymbol());
              } else {
                board[newRowNum - 1][newColNum - 1] = owner->getSymbol();
              }
            }
            board[rowNum - 1][colNum - 1] = '*';
            return;
          }
          // checking for jumping
          else if ((board[realNewRowNum][realNewColNum] == 'a') |
                   (board[realNewRowNum][realNewColNum] == 'A') |
                   (board[realNewRowNum][realNewColNum] == 'b') |
                   (board[realNewRowNum][realNewColNum] == 'B')) {
            if ((colNum - 1) < realNewColNum) {
              // king jumps backwards right
              if (isupper(board[rowNum - 1][colNum - 1])) {
                if ((rowNum - 1) < realNewRowNum) {
                  board[rowNum - 1][colNum - 1] = '*';
                  board[realNewRowNum][realNewColNum] = '*';
                  board[realNewRowNum + 1][realNewColNum + 1] =
                      toupper(owner->getSymbol());
                  return;
                }
                // king jumps forwards right
                else if ((rowNum - 1) > realNewRowNum) {
                  board[rowNum - 1][colNum - 1] = '*';
                  board[realNewRowNum][realNewColNum] = '*';
                  board[realNewRowNum - 1][realNewColNum - 1] =
                      toupper(owner->getSymbol());
                  return;
                }
              }

              // normal jumps forwards right
              else if (islower(board[rowNum - 1][colNum - 1])) {
                board[rowNum - 1][colNum - 1] = '*';
                board[realNewRowNum][realNewColNum] = '*';
                board[realNewRowNum - 1][realNewColNum + 1] =
                    owner->getSymbol();
                if ((newRowNum - 2) == 0) {
                  board[realNewRowNum - 1][realNewColNum + 1] =
                      toupper(owner->getSymbol());
                }
                return;
              }
            } else if ((colNum - 1) > realNewColNum) {
              // king jumps backwards left
              if (isupper(board[rowNum - 1][colNum - 1])) {
                if ((rowNum - 1) < realNewRowNum) {
                  board[rowNum - 1][colNum - 1] = '*';
                  board[realNewRowNum][realNewColNum] = '*';
                  board[realNewRowNum + 1][realNewColNum - 1] =
                      toupper(owner->getSymbol());
                  return;
                }
                // king jumps forwards left
                else if ((rowNum - 1) > realNewRowNum) {
                  board[rowNum - 1][colNum - 1] = '*';
                  board[realNewRowNum][realNewColNum] = '*';
                  board[realNewRowNum - 1][realNewColNum - 1] =
                      toupper(owner->getSymbol());
                  return;
                }
              }
              // normal jumps forwards left
              else if (islower(board[rowNum - 1][colNum - 1])) {
                board[rowNum - 1][colNum - 1] = '*';
                board[realNewRowNum][realNewColNum] = '*';
                board[realNewRowNum - 1][realNewColNum - 1] =
                    owner->getSymbol();
                if ((newRowNum - 2) == 0) {
                  board[realNewRowNum - 1][realNewColNum - 1] =
                      toupper(owner->getSymbol());
                }
                return;
              }
            }
          }
        }

      } catch (runtime_error &excpt) {
        cout << excpt.what() << endl;
        cout << "Please try again" << endl;
        // g.movePiece(Player *owner, int row, int col);
      }
    } while (flag == false);
  } else {
    cout << owner->getName()
         << ", you have no more pieces. Your turn is now skipped." << endl;
    return;
  }
}

bool Gameboard::checkWin() {
  int p1Count = 0;
  int p2Count = 0;
  int p3Count = 0;
  int p4Count = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((board[i][j] == 'a') | (board[i][j] == 'A')) {
        p1Count += 1;
      } else if ((board[i][j] == 'b') | (board[i][j] == 'B')) {
        p2Count += 1;
      } else if ((board[i][j] == 'c') | (board[i][j] == 'C')) {
        p3Count += 1;
      } else if ((board[i][j] == 'd') | (board[i][j] == 'D')) {
        p4Count += 1;
      }
    }
  }

  if (((p1Count + p2Count == 0)) || ((p3Count + p4Count == 0))) {
    return true;
  }
  return false;
}

void Gameboard::displayWin() {
  int p1Count;
  int p2Count;
  int p3Count;
  int p4Count;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((board[i][j] == 'a') | (board[i][j] == 'A')) {
        p1Count += 1;
      } else if ((board[i][j] == 'b') | (board[i][j] == 'B')) {
        p2Count += 1;
      } else if ((board[i][j] == 'c') | (board[i][j] == 'C')) {
        p3Count += 1;
      } else if ((board[i][j] == 'd') | (board[i][j] == 'D')) {
        p4Count += 1;
      }
    }
  }

  if (((p1Count == 0) & (p2Count == 0))) {
    cout << "CONGRAGULATIONS TEAM 1! You have won Four Player Checkers" << endl;
  } else if (((p3Count == 0) & (p4Count == 0))) {
    cout << "CONGRAGULATIONS TEAM 2! You have won Four Player Checkers" << endl;
  }
}
