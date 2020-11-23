/*************************************************************************
 * File Name:       instructions.cpp
 * Course:          CPTR 142
 * Copyright (c) 2020-present, CPTR 245
 * All rights reserved
 */
//#ifndef SRC_INSTRUCTIONS_CPP_
//#define SRC_INTRUSCTIONS_CPP_
#include "instructions.h"
#include <iostream>

void getInstructions() {
  std::cout << std::endl;
  std::cout << "INSTRUCTIONS:" << std::endl;
  std::cout << std::endl;
  std::cout << " Playing  - There will be two teams of two players "
            << std::endl;
  std::cout
      << "            Player 1 will move first, then player 3, then 2, then 4."
      << std::endl;
  std::cout << "            Teams will alternate turns during the game."
            << std::endl;
  std::cout << std::endl;
  std::cout << " Movement - Basic movement is to move a checker one space "
               "diagonally forward."
            << std::endl;
  std::cout << "            You will enter the coordinates of the piece you "
               "want to move "
            << std::endl;
  std::cout << "            (ONLY ENTER THE COORDINATES OF A PIECE YOU CAN "
               "MOVE) and then "
            << std::endl;
  std::cout << "            the coordinates of the square " << std::endl;
  std::cout << "            you want to move to." << std::endl;
  std::cout << std::endl;
  std::cout << "            You can not move a checker backwards until it "
            << "becomes a King, as described below." << std::endl;
  std::cout << "            You can only move one space at a time and then it "
            << "is the next players turn" << std::endl;
  std::cout << "            (unless you make a double or more jump as seen "
            << "below)." << std::endl;
  std::cout << std::endl;
  std::cout << " Jumping  - If one of your opponent’s checkers is on a square "
               "a row ahead and a column "
            << "diagonal to one of your checkers, " << std::endl;
  std::cout
      << "            and the next space beyond the opponent’s checker is "
      << "empty, enter the coordinates of the opponents piece and your checker "
         "will jump the "
      << std::endl;
  std::cout << "            opponent’s checker and land "
            << "in the space beyond. " << std::endl;
  std::cout << "            Your opponent’s checker is captured and removed "
            << "from the board." << std::endl;
  std::cout << "            After making one jump, your checker might have "
            << "another jump available from its new position. " << std::endl;
  std::cout << "            Your checker must take that jump too. "
            << std::endl;
  std::cout << "            It must continue to jump until there are no more "
            << "jumps available. " << std::endl;
  std::cout << "            Both men and kings are allowed to make multiple "
            << "jumps." << std::endl;
  std::cout << "            It is your choice to jump another player, if you "
               "choose to,"
            << std::endl;
  std::cout << "            you may only jump one piece at a time."
            << std::endl;
  std::cout << std::endl;
  std::cout << " Crowning - When one of your checkers reaches the opposite "
            << "side of the board, it is crowned and becomes a King. ";
  std::cout << "Your turn ends there. " << std::endl;
  std::cout << "            A King can move backward as well as forward along "
            << std::endl;
  std::cout
      << "            the diagonals. It can only move a distance of one space. "
      << std::endl;
  std::cout << "            A King can also jump backward and forward. It must "
            << "jump when possible," << std::endl;
  std::cout << "            it must take all jumps that are "
            << "available to it. " << std::endl;
  std::cout << "            In each jump, the King can only jump over one "
            << std::endl;
  std::cout << "            opposing piece at a time, and it must land in the "
               "space just "
            << std::endl;
  std::cout << "            beyond the captured piece. " << std::endl;
  std::cout << "            The King can not move multiple spaces before or "
            << "after jumping a piece." << std::endl;
  std::cout << std::endl;
  std::cout << " Winner   - When one team has jumped all of the oposing teams "
            << "checker pieces, they have won the game." << std::endl;
  std::cout << "            A winner will not be declared until the end of a "
               "turn sequence."
            << std::endl;
  std::cout << std::endl;
}

//#endif