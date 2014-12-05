#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include "Game.h"
#include <string>
#include <vector>
#include "Card.h"

using std::vector;
using std::string;


class Move

{

	friend class Player; // so that after validation, Player can look into Move object to get stored Card *

private:
	Field * field; // how we'll access Field, and thus see if moves are valid

// 	OList<Card *> hand; //separate linked list of resource cards for the hand


	string type; // "camels" (take all camels) || "take" || "exchange" || "sell"
	bool validMove;

	// these members represent all the potential values that might need to get filled with respective cards
	// they will be accessed by Player after validation to easily obtain the Card *, without having to repeat the code to
		// convert the initial arguments (letters and numbers) into Card *
	Card * takeSingle;
    vector<Card * > takeMult;
    vector<Card * > returnMult;
    vector<Card * > sell;
    vector<Card * > fieldCamels;

public:
	Move(): field(NULL), player(NULL), type(""), validMove(false) {}; 
	Move(Field * f, OList<Card *> & handRef); // use of this constructor means: "camels"
	Move(Field * f, OList<Card *> & handRef, vector<int>); // use of this constructor means: "sell"
	Move(Field * f, OList<Card *> & handRef, vector<int>, vector<char>); // use of this constructor means: "exchange"
	Move(Field * f, OList<Card *> & handRef, char); // use of this constructor means: "take"

	bool isValid() {return validMove;};

private:
	bool checkRepeats(vector<Card *> cardList);

};


#endif // MOVE_H_INCLUDED
