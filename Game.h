#ifndef _GAME_H
#define _GAME_H

#include "Field.h"
#include "State.h"
#include "Player.h"
#include "Bank.h"
#include <iostream> // recently added
#include <cstdio> // recently added
#include <cstdlib> // recently added

class Player;
class Move;

class Game {

private:

	Field field; // default constructor gets called automatically upon game objection creation
	Bank bank; // default constructor gets called automatically upon game objection creation

	Player* playersInGame[2];
	int roundNum;
	State gameState;
	int playerWinnerIndex;

public:

    Game(); // requires immediate attention
    Game(Game &);
    ~Game();

	void playGame();
	void initPlayers(); // kush and mao
	void initBank();

private:

    void printBoard();
	int getRoundNum() const { return roundNum; };
	Player & setWinner( int );
	bool roundIsOver();
	bool gameOver();
	void shuffleDeck();
	void deal();

};

#endif
