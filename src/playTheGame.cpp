/*************************************************************************
 * File Name:       playTheGame.cpp
 * Course:          CPTR 142
 * Copyright (c) 2020-present, CPTR 245
 * All rights reserved
 */

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Checkers.h"
#include "Gameboard.h"
#include "King.h"
#include "Player.h"
#include "instructions.h"
#include "playTheGame.h"

char userInput() {
  char userChoice;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << "WELCOME TO OUR FOUR PLAYER CHECKER GAME!!!" << endl;
  cout << "Enter your choice: " << endl;
  cout << "1 to view the instructions" << endl;
  cout << "2 to play the game" << endl;
  cout << "3 to exit the game" << endl;
  cout << "Choice ";
  cin >> userChoice;
  cout << endl;

  // error check
  if ((userChoice != '1') & (userChoice != '2') & (userChoice != '3')) {
    cerr << "Enter a valid choice" << endl;
  }
  cout << endl;

  return userChoice;
}

void inputNames() {

  string name;

  cout << "Enter the name for Player 1: ";
  cin >> name;
  Player player1(name, 'a', 1);
  Player *player1ptr;
  player1ptr = &player1;

  cout << endl;

  cout << "Enter the name for Player 2: ";
  cin >> name;
  Player player2(name, 'b', 1);
  Player *player2ptr;
  player2ptr = &player2;
  cout << endl;

  cout << "Enter the name for Player 3: ";
  cin >> name;
  Player player3(name, 'c', 2);
  Player *player3ptr;
  player3ptr = &player3;
  cout << endl;

  cout << "Enter the name for Player 4: ";
  cin >> name;
  Player player4(name, 'd', 2);
  Player *player4ptr;
  player4ptr = &player4;
  cout << endl;

  Gameboard gameboard;

  int rowNum;
  int colNum;

  // show board
  cout << endl;
  gameboard.setCheckers();
  gameboard.drawBoard();
  cout << endl;

  // let players know thier pieces
  cout << player1.getName() << " will use the pieces labeled "
       << player1.getSymbol() << endl;
  cout << player2.getName() << " will use the pieces labeled "
       << player2.getSymbol() << endl;
  cout << player3.getName() << " will use the pieces labeled "
       << player3.getSymbol() << endl;
  cout << player4.getName() << " will use the pieces labeled "
       << player4.getSymbol() << endl;
  cout << endl;

  // ACTUAL GAMEPLAY
 
do{

  try {
    // player 1 move

    // cout << player1.getTeam();
    // cout << player1.getSymbol();
    gameboard.movePiece(player1ptr);
    gameboard.drawBoard();

  } catch (runtime_error &excpt) {
    cout << excpt.what() << endl;
    cout << "Please try again" << endl;
    gameboard.drawBoard();
  }

  // player 3 move

  try {
    // cout << player3.getTeam();
    // cout << player3.getSymbol();
    gameboard.movePiece(player3ptr);
    gameboard.drawBoard();
  }
  // if error allow player to try again
  catch (runtime_error &excpt) {
    cout << excpt.what() << endl;
    cout << "Please try again" << endl;
    // gameboard.movePiece(player3ptr, rowNum, colNum);
    gameboard.drawBoard();
  }

  // player 2 move

  try {
    gameboard.movePiece(player2ptr);
    gameboard.drawBoard();
  }
  // if error allows player to try again
  catch (runtime_error &excpt) {
    cout << excpt.what() << endl;
    cout << "Please try again" << endl;
    // gameboard.movePiece(player2ptr, rowNum, colNum);
    gameboard.drawBoard();
  }

  // player 4 move

  try {
    gameboard.movePiece(player4ptr);
    gameboard.drawBoard();
  }
  // if error, allows player to try again
  catch (runtime_error &excpt) {
    cout << excpt.what() << endl;
    cout << "Please try again" << endl;
    // gameboard.movePiece(player4ptr, rowNum, colNum);
    gameboard.drawBoard();
  }
} while (gameboard.checkWin() == false);
if (gameboard.checkWin() == true){
    gameboard.displayWin();
}
}
// display win



void playTheGame() {
  while (true) {
    char results = userInput();

    switch (results) {
    case '1':
      getInstructions();
      break;

    case '2':
      inputNames();
      break;

    case '3':
      cout << "Thanks for playing!" << std::endl;
      exit(1);
      break;
    }
  }
}
