#include "Move.h"

Move::Move(Field * f, OList<Card *> & handRef) // use of this constructor means: "camels"
{
	type = "camels";
	field = f;

	vector<Card *>::iterator iterMarket = field->market.begin();

	while(iterMarket != field->market.end())
	{
		if((*(*iterMarket)).Card::getIsCamel())
		{
			fieldCamels.push_back(iterMarket);
			// do I need to increment iterCamels???
		}
		iterMarket++;
	}

	if(fieldCamels.size() == 0) // 0 camels
	{
		validMove = false;
		// throw exception??
		return;
	}
	else
		validMove = true;
}

Move::Move(Field * f, OList<Card *> & handRef, vector<int> cardsToSell) // use of this constructor means: "sell"
{
	type = "sell";
	field = f;

	// fill sell with iterators pointing to all cards being sold
	fetchHandCards(cardsToSell, handRef, sell);

	// now, sell vector should contain iterators pointing to all the cards that the player wants to sell
	// we want to check that these cards can, indeed, be sold

	vector< OListIterator<Card *> >::iterator sellIter = sell.begin();

	// check that all the cards being sold are the same type
	string type = (*(*(*sellIter++))).Card::getIdentifier(); //triple dereference gets to the Card
	while(sellIter != sell.end())
	{
		if((*(*(*sellIter++))).Card::getIdentifier() != type)
		{
			validMove = false;
			// throw exception?
			return;
		}
	}
	// check that if cards are precious, then num cards being sold >=2
	sellIter = sell.begin();
	if((***sellIter).Card::getPrecious())
	{
		if(sell.size() < 2){
			validMove = false;
			// throw exception?
			return;
		}
	}

	validMove = true;

}

Move::Move(Field * f, OList<Card *> & handRef, vector<int> cardsToGive, vector<char> cardsToTake, int num_camels, vector<Card *> & herd) // use of this constructor means: "exchange"
{
	//////////// PRELIMINARY CHECKS //////////////
	// check that player isn't taking more than 7 cards
	if((handRef.size() + cardsToTake.size() - cardsToGive.size()) > 7)
	{
		validMove = false;
		// throw exception?? -- invalid # of arguments (too many takes)
	}
	// check that # camels + # cardsToGive == # cardsToTake
	if((num_camels + cardsToGive.size()) != cardsToTake.size())
	{
		validMove = false;
		// throw exception?? -- invalid # of arguments
	}
	// check that player has # camels
	if(herd.size() < num_camels)
	{
		validMove = false;
		// throw exception?? -- invalid # of arguments (too many camels)
	}
	// check that player has # cardsToGive ???

	type = "exchange";
	field = f;

	// fill returnMult with iterators pointing to all cards being given
	fetchHandCards(cardsToGive, handRef, returnMult);
	// fill takeMult with iterators pointing to all cards being taken
	fetchMarketCards(cardsToTake, takeMult);

	// now, returnMult and takeMult vectors should contain iterators pointing to all the cards that the player wants to exchange
	// we want to check that these cards can, indeed, be exchanged

	//////////// FINAL CHECKS //////////////
	// check that same type card isn't being given and taken
	// dealing with camels??? wtf.
}

Move::Move(Field * f, OList<Card *> & handRef, char) // use of this constructor means: "take"
{


}

void Move::fetchHandCards(vector<int> cardIndices, OList<Card *> & handRef, vector< OListIterator<Card *> > & iterators_Vector)
{
	// first check to ensure no repeats
	vector<int>::iterator iter1;
	vector<int>::iterator iter2;
	for(iter1 = cardIndices.begin(); iter1 != cardIndices.end(); iter1++)
	{
		for(iter2 = iter1 + 1; iter2 != cardIndices.end(); iter2++)
		{
			if(*iter1 == *iter2)
			{
				validMove = false;
				// throw exception??
				return;
			}
		}
	}

	////////////// now actually fetch the cards //////////////////

	int curr; // pre-declaration

	OListIterator<Card *> iterHand = handRef.begin();
	vector<int>::iterator iterCardIndices = cardIndices.begin();

	// add Card * of cards to sell to vector<Card *> sell
	while(iterCardIndices != cardIndices.end())
	{
		curr = *iterCardIndices;
		curr--;
		while(curr != 0 && iterHand != handRef.end())
		{
			iterHand++;
			curr--;
		}
		if(iterHand != handRef.end())
			iterators_Vector.push_back(iterHand);
		// else throw exception?? --- outOfRange

		iterHand = handRef.begin(); // reset iterHand to beginning of OList hand
		iterCardIndices++;
	}

}

void Move::fetchMarketCards(vector<char> cardIndices, vector< vector<Card *>::iterator > & iterators_Vector)
{
	// first check to ensure no repeats
	vector<char>::iterator iter1;
	vector<char>::iterator iter2;
	for(iter1 = cardIndices.begin(); iter1 != cardIndices.end(); iter1++)
	{
		for(iter2 = iter1 + 1; iter2 != cardIndices.end(); iter2++)
		{
			if(*iter1 == *iter2)
			{
				validMove = false;
				// throw exception?? --- outOfRange
				return;
			}
		}
	}

	////////////// now actually fetch the cards //////////////////

	char curr; // pre-declaration

	vector<Card *>::iterator iterMarket = field->market.begin();
	//----- OListIterator<Card *> iterHand = handRef.begin();
	vector<char>::iterator iterCardIndices = cardIndices.begin();

	// add Card * of cards to sell to vector<Card *> sell
	while(iterCardIndices != cardIndices.end())
	{
		curr = *iterCardIndices;
		curr--;
		while(curr != 'a'-1 && iterMarket != field->market.end())
		{
			iterMarket++;
			curr--;
		}
		if(iterMarket != field->market.end())
			iterators_Vector.push_back(iterMarket);
		// else throw exception??

		iterMarket = field->market.begin(); // reset iterMarket to beginning of OList hand
		iterCardIndices++;
	}

}
