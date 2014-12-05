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

	type = "exchange";
	field = f;
	
	//////////// PRELIMINARY CHECKS //////////////
	// check that player isn't taking more than 7 cards into hand
	if((handRef.size() + cardsToTake.size() - cardsToGive.size()) > 7)
	{
		validMove = false;
		// throw exception?? -- invalid # of arguments (too many takes)
		return;
	}
	// check that # camels + # cardsToGive == # cardsToTake
	if((num_camels + cardsToGive.size()) != cardsToTake.size())
	{
		validMove = false;
		// throw exception?? -- invalid # of arguments
		return;
	}
	/* check that player isn't giving market more than 5 cards 
		this can be verified by ensuring that #cardsToTake <= 5 */
	if(cardsToTake.size() <= 5)
	{
		validMove = false;
		// throw exception?? -- invalid # of arguments
		return;
	}
	// check that player has # camels
	if(herd.size() < num_camels)
	{
		validMove = false;
		// throw exception?? -- invalid # of arguments (too many camels)
		return;
	}
	// check that player has # cardsToGive ???
	if(handRef.size() < cardsToGive.size())
	{
		validMove = false;
		// throw exception?? -- invalid # of arguments
		return;
	}

	// fill returnMult with iterators pointing to all cards being given
	fetchHandCards(cardsToGive, handRef, returnMult);
	// fill takeMult with iterators pointing to all cards being taken
	fetchMarketCards(cardsToTake, takeMult);

	// now, returnMult and takeMult vectors should contain iterators pointing to all the cards that the player wants to exchange
	// we want to check that these cards can, indeed, be exchanged

	vector<	vector<Card *>::iterator >::iterator takeIter;
	vector< OListIterator<Card *> >::iterator returnIter;

	//////////// FINAL CHECKS //////////////
	// check that same type card isn't being given and taken
	for(returnIter = returnMult.begin(); returnIter != returnMult.end(); returnIter++)
	{

		for(takeIter = takeMult.begin(); takeIter != takeMult.end(); takeIter++)
		{			
			if( (***returnIter).Card::getIdentifier() == 
				(***takeIter).Card::getIdentifier())
			{
				validMove = false;
				// throw exception?? -- cannot exchange same type of card
				return;
			}
		}
	}
	/* check that cards being taken don't include mixture of camels and goods
		Do this by ensuring that none of the taken cards are camels */
	for(takeIter = takeMult.begin(); takeIter != takeMult.end(); takeIter++)
	{
		if( (***takeIter).Card::getIsCamel() )
		{
			validMove = false;
			// throw exception?? -- cannot exchange and take camels	
			return;		
		}
	}

	validMove = true;
	num_camels_exchanged = num_camels;
}

Move::Move(Field * f, OList<Card *> & handRef, char index) // use of this constructor means: "take"
{
	type = "take";
	field = f;
	
	////////// preliminary testing ////////////////
	// shouldn't have 7 cards in hand already
	if(handRef.size() >= 7)
	{
		validMove = false;
		// throw exception?? -- hand already full
		return;	
	}

	fetchSingleMarketCard(index, takeSingle);

	////////// final testing //////////////////////
	// shouldn't be a camel
	if((**takeSingle).Card::getIsCamel)
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

void fetchSingleMarketCard(char cardIndex, vector< Card *>::iterator & iter)
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