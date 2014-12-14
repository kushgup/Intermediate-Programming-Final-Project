#include "Move.h"

Move::Move(Field * f): type("camels") // use of this constructor means: "camels"
{
	vector<Card *>::iterator iterMarket = f->market.begin(), iterMarket_end = f->market.end();

	while(iterMarket != iterMarket_end)
	{
		if((**iterMarket).getIsCamel())
		{
			fieldCamels.push_back(iterMarket);
			// do I need to increment iterCamels???
		}
		iterMarket++;
	}
    
	if(fieldCamels.size() == 0) // 0 camels
		throw noCamels(); 
}

Move::Move(OList<Card *> & handRef, vector<int> cardsToSell): type("sell") // use of this constructor means: "sell"
{
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
			throw wrongSellType();

	}
	// check that if cards are precious, then num cards being sold >=2
	sellIter = sell.begin();
	if((***sellIter).Card::getPrecious())
	{
		if(sell.size() < 2)
			throw sellPrecious();
	}

	validMove = true;
}

// use of this constructor means: "exchange"
Move::Move(Field * f, OList<Card *> & handRef, vector<int> cardsToGive, vector<char> cardsToTake, int num_camels, vector<Card *> & herd): type("exchange"), num_camels_exchanged(num_camels) 
{
	//////////// PRELIMINARY CHECKS //////////////
	bool too_many_takes = (handRef.size() + cardsToTake.size() - cardsToGive.size()) > 7; 	// check that player isn't taking more than 7 cards into hand
	bool equal_args = (num_camels + cardsToGive.size()) != cardsToTake.size(); 	// check that # camels + # cardsToGive == # cardsToTake
	bool market_size = cardsToGive.size() > 5; // check that player isn't giving market more than 5 cards 
	bool herd_size = (int) herd.size() < num_camels; 	// check that player has # camels
	bool hand_size = (int)handRef.size() < (int)cardsToGive.size(); 	// check that player has # cardsToGive ???

	if (too_many_takes || equal_args || market_size || herd_size || hand_size) {
		validMove = false;
		cout << "0" << endl; // DEBUGGING
		//throw exceptions based on what was false
		return;
	}

	fetchHandCards(cardsToGive, handRef, returnMult); // fill returnMult with iterators pointing to all cards being given
	fetchMarketCards(cardsToTake, takeMult, f); // fill takeMult with iterators pointing to all cards being taken

	// now, returnMult and takeMult vectors should contain iterators pointing to all the cards that the player wants to exchange
	// we want to check that these cards can indeed be exchanged
	vector<	vector<Card *>::iterator >::iterator takeIter;
	vector< OListIterator<Card *> >::iterator returnIter;
	//////////// FINAL CHECKS //////////////
	// check that same type card isn't being given and taken
	for(returnIter = returnMult.begin(); returnIter != returnMult.end(); returnIter++) {
		for(takeIter = takeMult.begin(); takeIter != takeMult.end(); takeIter++) {			
			if( (***returnIter).Card::getIdentifier() == (***takeIter).Card::getIdentifier() ) {
				validMove = false;
				cout << "1" << endl; // DEBUGGING

				// throw exception?? -- cannot exchange same type of card
				return;
			}
		}
	}
	/* check that cards being taken don't include mixture of camels and goods
		Do this by ensuring that none of the taken cards are camels */
	for(takeIter = takeMult.begin(); takeIter != takeMult.end(); takeIter++) {
		if( (***takeIter).Card::getIsCamel() ) {
			validMove = false;
			cout << "2" << endl; // DEBUGGING

			// throw exception?? -- cannot exchange and take camels	
			return;		
		}
	}

	validMove = true;
}

Move::Move(Field * f, OList<Card *> & handRef, char index): type("take") // use of this constructor means: "take"
{
	////////// preliminary testing ////////////////
	// shouldn't have 7 cards in hand already
	if(handRef.size() >= 7)
	{
		validMove = false;
		// throw exception?? -- hand already full
		return;	
	}

	fetchSingleMarketCard(index, takeSingle, f);

	////////// final testing //////////////////////
	// shouldn't be a camel
	if((**takeSingle).Card::getIsCamel())
	{
		validMove = false;
		// throw exception?? -- cannot take a single camel
		return;		
	}

	validMove = true;
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

void Move::fetchMarketCards(vector<char> cardIndices, vector< vector<Card *>::iterator > & iterators_Vector, Field * field)
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
		while(curr != 'a' - 1 && iterMarket != field->market.end())
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

void Move::fetchSingleMarketCard(char cardIndex, vector< Card *>::iterator & iter, Field * field)
{
	////////////// to fetch the card //////////////////

	vector<Card *>::iterator iterMarket = field->market.begin();

	cardIndex--;
	while(cardIndex != 'a'-1 && iterMarket != field->market.end())
	{
		iterMarket++;
		cardIndex--;
	}
	if(iterMarket != field->market.end())
		iter = iterMarket;
	// else throw exception??
}
