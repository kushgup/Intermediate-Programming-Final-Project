#ifndef _GAME_H
#define _GAME_H

#include "State.h"
#include "PlayerComp.h"
#include "PlayerHuman.h"
#include <iostream> // recently added
#include <cstdio> // recently added
#include <cstdlib> // recently added
#include "Card.h"

class Player;
class PlayerComp;
class PlayerHuman;

class Game {

private:

	Field field; // default constructor gets called automatically upon game objection creation
	Bank bank; // default constructor gets called automatically upon game objection creation
	Player* players[2];
	int roundNum;
	int playerWinnerIndex; //keep track of starting player
	//State gameState;

public:

    Game(); //default constructor
    //Game(Game &); //copy constructor
    //~Game();

	void playGame(); // move to private area eventually...
	void initPlayers();

private:

    void printBoard();
	int getRoundNum() const { return roundNum; };
//	Player & setWinner(int x) { return players[x]; } ;
	bool roundIsOver();
	bool gameOver();
	void shuffleDeck();
	void deal();
	void calculateWinner();

};

#endif
