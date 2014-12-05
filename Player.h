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

using std::vector; using std::string;

class Move;

class Player {

	friend class Move; //so Move can look at player's hand and herd

protected:

	Game * player_game;
	string name; //store the name of the player
	OList<Card *> hand; //separate linked list of resource cards for the hand
	vector<Card*> herd; //separate linked list of camels
	vector<Token *> seals; //keep track of how many seals the player has
	vector<Token *> tokens; //keep track of tokens collected

public:

	Player(string nm, Game * gm): name(nm), player_game(gm) { }

	string getName() const { return name; };
	int handSize() const { return hand.size(); };
	int numCamels() const { return camels.size(); };
	int countPts() const;
	int countSeals() const { return seals.size(); };
	void printHand() const;
	virtual void makeMove() = 0; //decides which action to take on the turn, should be overwritten for human and AI players

protected:

	void takeCamels(Move to_make); //option 1, take all the camels in the market
	void takeCard(Move to_make); //option 2, take a single card from market
	void exchange(Move to_make); //option 3, take multiple cards from market and exchange from hand and/or camels
	void sellCards(Move to_make); //option 4, sell cards from the hand
};

//need overloaded operators (typecast, >> << for input/output, all the == stuff), exception handling, and test cases

#endif
