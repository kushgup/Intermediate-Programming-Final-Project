/*
This class defines the Human player, inherits from the abstract base class Player
The only definitions in this file are overriding the virtual functions defined in Player.h
*/

#ifndef _HUMANPLAYER_H
#define _HUMANPLAYER_H

#include "Player.h"

class HumanPlayer: public Player {

public:
	
	void makeMove(); //decides which action to take on the turn
};

#endif
