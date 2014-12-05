#ifndef _GAME_H
#define _GAME_H

#include "Field.h"

class Game {

	friend class Move; // needed so that Move can access Game's field
	friend class Player; // needed so that Player can look into Game's field to move stuff

private:

	Player players[2];
	int roundNum;
	State gameState;
	Field field;

public:

	void printBoard();
	int roundNum();
	Player & getWinner();
	void initPlayers();
	bool isOver();
	void createDeck();
	void shuffleDeck();
	void deal();

};

#endif
