#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include "Game.h"

class Move

{

private:
	Game * game; // how we'll access Game's Field, and thus see if moves are valid
	Player * player; // how we'll access Player's hand / herd, see if moves are valid

};


#endif // MOVE_H_INCLUDED
