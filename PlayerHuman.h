/*
This class defines the Human player, inherits from the abstract base class Player
The only definitions in this file are overriding the virtual functions defined in Player.h
*/

#ifndef _HUMANPLAYER_H
#define _HUMANPLAYER_H

#include "Player.h"

class HumanPlayer: public Player {

public:
	
	void makeMove(); //called from Game, decides which action to take on the turn

private: //these are only called from makeMove

	void takeCard(); //option 1, take a single card from market
	void exchange(); //option 2, take multiple cards from market and exchange from hand and/or camels
	void sellCards(); //option 3, sell cards from the hand
	//note that all input and output from player will be implemented within these functions
};

#endif
