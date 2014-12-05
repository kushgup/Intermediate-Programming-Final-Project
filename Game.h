#ifndef _GAME_H
#define _GAME_H

#include "Field.h"
#include "State.h"
#include "Player.h"
#include "Bank.h"

class Player;
class Move;

class Game {

	friend class Move; // needed so that Move can access Game's field
	friend class Player; // needed so that Player can look into Game's field to move stuff

private:

	Player * players[2];
	int roundNum;
	State gameState;
	Field field;
	Bank bank;

public:

    Game();
    Game(Game &);
    ~Game();

	void playGame();

private:
    void setPlayers();
    void printBoard();
	int getRoundNum() const { return roundNum; };
	Player & getWinner();
	bool isOver();
	void createDeck();
	void shuffleDeck();
	void deal();

};

#endif
