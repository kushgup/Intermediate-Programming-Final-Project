#ifndef _GAME_H
#define _GAME_H

class Game {

private:

	Player players[2];
	int roundNum;
	Board board;
	State gameState;
	
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
