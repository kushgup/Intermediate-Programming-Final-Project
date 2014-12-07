#ifndef _MOVE_H_INCLUDED
#define _MOVE_H_INCLUDED

#include <string>
#include <vector>
#include "Card.h"
#include "Field.h"
#include "OListIterator.h"

using std::vector;
using std::string;

class Move
{

public://private:
	friend class Player; // so that after validation, Player can look into Move object to get stored Card *

public://private:
	Field * field; // how we'll access Field, and thus see if moves are valid

	string type; // "camels" (take all camels) || "take" || "exchange" || "sell"
	bool validMove;

	int num_camels_exchanged;

	// these members represent all the potential values that might need to get filled with respective cards
	// they will be accessed by Player after validation to easily obtain the Card *, without having to repeat the code to
		// convert the initial arguments (letters and numbers) into Card *


	/*********************************************************************************************/
	// the old
	/*
	Card * takeSingle;
    vector<Card * > takeMult;
    vector<Card * > returnMult;
    vector<Card * > sell;
    vector<Card * > fieldCamels;
    */

    // the new
    vector< Card *>::iterator takeSingle; // take ...... iterator for field
    vector<	vector<Card *>::iterator > takeMult; // exchange ...... iterator for field
    vector< OListIterator<Card *> > returnMult; // exchange ...... iterator for OList hand
    vector< OListIterator<Card *> > sell; // sell ...... iterator for OList hand
    vector<	vector<Card *>::iterator > fieldCamels; // takeCamels ...... iterator for field

	/*********************************************************************************************/

public:
	Move(): field(NULL), type(""), validMove(false) {};
	Move(Field * f); // use of this constructor means: "camels"
	Move(Field * f, OList<Card *> & handRef, vector<int>); // use of this constructor means: "sell"
	Move(Field * f, OList<Card *> & handRef, vector<int>, vector<char>, int num_camels, vector<Card *> &); // use of this constructor means: "exchange"
	Move(Field * f, OList<Card *> & handRef, char); // use of this constructor means: "take"

	bool isValid() {return validMove;};

private:
	void fetchHandCards(
		vector<int> cardIndices,
		OList<Card *> & handRef,
		vector< OListIterator<Card *> > & iterators_Vector
	);
	void fetchMarketCards(
		vector<char> cardIndices,
		vector< vector<Card *>::iterator > & iterators_Vector
	);
	void fetchSingleMarketCard(
		char cardIndex,
		vector< Card *>::iterator & iter
	);

};

#endif // MOVE_H_INCLUDED
