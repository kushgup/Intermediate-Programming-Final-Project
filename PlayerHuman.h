/*
This class defines the Human player, inherits from the abstract base class Player
The only definitions in this file are overriding the virtual functions defined in Player.h
*/

#ifndef _PLAYERHUMAN_H
#define _PLAYERHUMAN_H

#include "Player.h"
#include <cctype>

class PlayerHuman: public Player {

public:

	PlayerHuman(string nm, Field * fd, Bank * bk): Player(nm, fd, bk) { }
	~PlayerHuman() { };

	void makeMove(); //decides which action to take on the turn
};

#endif
