/*
This class defines the abstract base class Player.
It has a bunch of instance data that a player has, and functions pertaining to decision making the turn
This class will be inherited by HumanPlayer and AIPlayer
*/

#ifndef _PLAYER_H
#define _PLAYER_H

#include "OList.h"
#include "Token.h"
#include "Card.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

class Player {

	friend class Move; // needed so that Move can look into Player hand / herd

protected:

	string name; //store the name of the player
	OList<Card *> hand; //separate linked list of resource cards for the hand
	vector<Card *> herd; //separate linked list of camels
	vector<Token *> seals; //keep track of how many seals the player has
	vector<Token *> tokens; //keep track of tokens collected

public:

	Player(string nm): name(nm) { }

	string getName() const { return name; };
	int handSize() const { return hand.size(); };
	int numCamels() const { return camels.size(); };
	int countPts() const;
	int countSeals() const { return seals.size(); };
	virtual void makeMove() = 0; //decides which action to take on the turn, should be overwritten for human and AI players

protected:

	void takeCamels(); //option 1, take all the camels in the market
	void takeCard(); //option 1, take a single card from market
	void exchange(); //option 2, take multiple cards from market and exchange from hand and/or camels
	void sellCards(); //option 3, sell cards from the hand
};

//need overloaded operators (typecast, >> <<, all the == stuff), exception handling, and test cases

#endif
