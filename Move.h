#ifndef _MOVE_H_INCLUDED
#define _MOVE_H_INCLUDED

#include <string>
#include <vector>
#include "Card.h"
#include "Field.h"
#include "OListIterator.h"
#include "Exceptions.h"

using std::vector;
using std::string;

class Move
{

private:
	friend class Player; // so that after validation, Player can look into Move object to get stored Card *

private:

	string type; // "camels" (take all camels) || "take" || "exchange" || "sell"
	int num_camels_exchanged;

	// these members represent all the potential values that might need to get filled with respective cards
	// these iterators will be accessed by Player after validation to easily obtain the Card *, without having to repeat the code to 
	// convert the initial arguments (letters and numbers) into Card *

    vector< Card *>::iterator takeSingle; // take ...... iterator for field
    vector<	vector<Card *>::iterator > takeMult; // exchange ...... iterator for field
    vector< OListIterator<Card *> > returnMult; // exchange ...... iterator for OList hand
    vector< OListIterator<Card *> > sell; // sell ...... iterator for OList hand
    vector<	vector<Card *>::iterator > fieldCamels; // takeCamels ...... iterator for field

	/*********************************************************************************************/

public:
	Move(): type("") {};
	Move(Field * f); // use of this constructor means: "camels"
	Move(OList<Card *> & handRef, vector<int>); // use of this constructor means: "sell"
	Move(Field * f, OList<Card *> & handRef, vector<int>, vector<char>, int num_camels, vector<Card *> &); // use of this constructor means: "exchange"
	Move(Field * f, OList<Card *> & handRef, char); // use of this constructor means: "take"

private:
	void fetchHandCards(
		vector<int> cardIndices,
		OList<Card *> & handRef,
		vector< OListIterator<Card *> > & iterators_Vector
	);
	void fetchMarketCards(
		vector<char> cardIndices,
		vector< vector<Card *>::iterator > & iterators_Vector, 
		Field *
	);
	void fetchSingleMarketCard(
		char cardIndex,
		vector< Card *>::iterator & iter,
		Field *
	);

};

#endif // MOVE_H_INCLUDED
