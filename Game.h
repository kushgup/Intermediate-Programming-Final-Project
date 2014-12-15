#ifndef _GAME_H
#define _GAME_H

#include "PlayerComp.h"
#include "PlayerHuman.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define num_players 2

class Player;
class PlayerComp;
class PlayerHuman;

class Game {

private:

	Field field; // default constructor gets called automatically upon game objection creation
	Bank bank; // default constructor gets called automatically upon game objection creation
	Player* players[num_players];
	int roundNum;
	int playerWinnerIndex; //keep track of starting player
	//State gameState;

public:

    Game(); //default constructor
    //Game(Game &); //copy constructor
    ~Game();

	void playGame(); // move to private area eventually...
	void initPlayers();

private:

    void printBoard();
	int getRoundNum() const { return roundNum; };
	bool roundIsOver();
	bool gameOver() const;
	void shuffleDeck();
	void deal();
	void calculateWinner();
	void printGameWinner() const;
	void printRoundWinner(int) const;

};

#endif
