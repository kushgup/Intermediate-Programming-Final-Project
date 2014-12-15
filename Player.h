/*
This class defines the abstract base class Player.
It has a bunch of instance data that a player has, and functions pertaining to decision making the turn
This class will be inherited by HumanPlayer and AIPlayer
*/

#ifndef _PLAYER_H
#define _PLAYER_H

#include "Bank.h"
#include "Move.h"
#include <string>
#include <vector>
#include <iostream>

using std::cout; using std::cin; using std::endl;
using std::vector; using std::string;

class Move; //??? maybe causes other issues

class Player {

	friend class Game; // allows Game class to access hand and deal initial hand

protected:

	string name; //store the name of the player
	Field * game_field; //store a pointer to the game's field
	Bank * game_bank; //store a pointer to the bank to take tokens when needed
	OList<Card *> hand; //separate linked list of resource cards for the hand
	vector<Card *> herd; //separate linked list of camels
	vector<Token *> seals; //keep track of how many seals the player has
	vector<Token *> tokens; //keep track of tokens collected

public:

	Player(string nm, Field * fd, Bank * bk): name(nm), game_field(fd), game_bank(bk) { }
	virtual ~Player() { };

	string getName() const { return name; };
	int handSize() const { return hand.size(); };
	int numCamels() const { return herd.size(); };
	int countPts() const;
	int countSeals() const { return seals.size(); };
	void printHand() const; //print name, hand, camel and point info
	void resetForRound(); //clear hand, herd, and tokens for a new round
    bool hasPandaCamel(); //for tiebreakers
	virtual void makeMove() = 0; //decides which action to take on the turn, should be overwritten for human and AI players

protected:

	void takeCamels(Move & to_make); //option 1, take all the camels in the market
	void takeCard(Move & to_make); //option 2, take a single card from market
	void exchange(Move & to_make); //option 3, take multiple cards from market and exchange from hand and/or herd
	void sellCards(Move & to_make); //option 4, sell cards from the hand
};

#endif
