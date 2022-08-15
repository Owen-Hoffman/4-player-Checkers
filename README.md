# 4 Player Checkers

Created for CPTR 142 under Professor James Foster

## Collaborators

* Joshua Mularczyk
* Christian Williams
* Owen Hoffman
* Cameron Penaflorida

## Problem Definition

The goal for this project is to design a game of checkers for four players.
The game will output instructions and how to play.
Each player will be able to enter their name and begin to take their turns.
After 3 of the players have lost all their pieces on the board, the last player standing will be declared winner.

### Key Features

* Game rules
* 4 players
* When piece is jumped, the piece gets removed
* Winner is declared (whoever has the last pieces standing)

### Assumptions

Person doesn't know how to play checkers

### Instructions

Playing  - There will be two teams of two players. 
Player 1 will move first, then player 3, then 2, then 4.
Teams will alternate turns during the game.

Movement - Basic movement is to move a checker one space diagonally forward.
You will enter the coordinates of the piece you want to move
(ONLY ENTER THE COORDINATES OF A PIECE YOU CAN MOVE) 
and then the coordinates of the square.
You can not move a checker backwards until it becomes a King, as described below.
You can only move one space at a time and then it is the next players turn
(unless you make a double or more jump as seen below).

Jumping - If one of your opponent’s checkers is on a square a row ahead and a column
diagonal to one of your checkers, and the next space beyond the opponent’s checker is
empty, enter the coordinates of the opponents piece and your checker will jump the
opponent’s checker and land in the space beyond.
Your opponent’s checker is captured and removed from the board.
After making one jump, your checker might have another jump available from its new position.
Your checker must take that jump too. 
It must continue to jump until there are no more jumps available.
Both men and kings are allowed to make multiple jumps.
It is your choice to jump another player, you may only jump one piece at a time.

Crowning - When one of your checkers reaches the opposite side of the board, it is crowned and becomes a King.
Your turn ends there. A King can move backward as well as forward along the diagonals.
It can only move a distance of one space. A King can also jump backward and forward. It must 
jump when possible. In each jump, the King can only jump over one opposing piece at a time, 
and it must land in the space just beyond the captured piece. The King can not move multiple spaces before or
after jumping a piece.

Winner - When one team has jumped all of the oposing teams checker pieces, they have won the game.
A winner will not be declared until the end of a turn sequence.

## Source Code

- [GitHub](https://github.com/Owen-Hoffman/4-player-Checkers)
