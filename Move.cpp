#include "Move.h"
#include "Field.h"
#include "OListIterator.h"

Move::Move(Field * f, OList<Card *> & handRef) // use of this constructor means: "camels"
{
	type = "camels";
	field = f;

	vector<Card *>::iterator iterMarket = field->market.begin();
	vector<Card *>::iterator iterCamels = fieldCamels.begin();

	while(iterMarket != field->market.end())
	{
		if((*(*iterMarket)).Card::getIsCamel())
		{
			iterCamels = fieldCamels.insert(iterCamels, *iterMarket);
			// do I need to increment iterCamels???
		}
		iterMarket++;
	}

	if(fieldCamels.size() == 0)
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

	// add Card * of cards to sell to vector<Card *> sell
	fetchHandCards(cardsToSell, handRef, sell);

	// now, sell vector should contain all the cards that the player wants to sell
	// we want to check that these cards can, indeed, be sold

	vector<Card *>::iterator sellIter = sell.begin();

	// check that there aren't repeats in the cards being sold
	if( !checkRepeats(sell) )
	{
		validMove = false;
		// throw exception??
		return;
	}
	// check that all the cards being sold are the same type
	string type = (*(*sellIter++)).Card::getIdentifier();
	while(sellIter != sell.end())
	{
		if((*(*sellIter++)).Card::getIdentifier() != type)
		{
			validMove = false;
			// throw exception?
			return;
		}
	}
	// check that if cards are precious, then num cards being sold >=2
	sellIter = sell.begin();
	if((**sellIter).Card::getPrecious())
	{
		if(sell.size() < 2){
			validMove = false;
			// throw exception?
			return;
		}
	}

	validMove = true;

}

Move::Move(Field * f, OList<Card *> & handRef, vector<int>, vector<char>) // use of this constructor means: "exchange"
{
	type = "exchange";
	field = f;
}

Move::Move(Field * f, OList<Card *> & handRef, char) // use of this constructor means: "take"
{


}

bool Move::checkRepeats(vector<Card *> cardList)
{
	vector<Card *>::iterator iter;
	vector<Card *>::iterator iter2 = cardList.begin();

	for(iter = cardList.begin(); iter != cardList.end(); iter++)
	{
		for(iter2 = iter + 1; iter != cardList.end(); iter2++)
		{
			if(*iter2 == *iter)
				return false;
		}
	}

	return true;
}

void Move::fetchHandCards(vector<int> cardIndices, OList<Card *> & handRef, vector<Card *> & cardPtrs)
{

	int curr; // pre-declaration

	OListIterator<Card *> iterHand = handRef.begin();
	vector<int>::iterator iterCardIndices = cardIndices.begin();

	// add Card * of cards to sell to vector<Card *> sell
	while(iterCardIndices != cardIndices.end())
	{
		curr = *iterCardIndices;
		while(--curr != 0 && iterHand != handRef.end())
		{
			iterHand++;
			curr--;
		}
		if(iterHand != handRef.end())
			cardPtrs.push_back(*iterHand);
		// else throw exception??

		iterHand = handRef.begin(); // reset iterHand to beginning of OList hand
		iterCardIndices++;
	}

}


