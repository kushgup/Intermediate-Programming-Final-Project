#include "Move.h"
#include "Field.h"
#include "OListIterator.h"

Move::Move(Field * f, OList<Card *> & handRef); // use of this constructor means: "camels"
{
	field = f;

	vector<Card *>::iterator iterMarket = game.field.market.begin();
	vector<Card *>::iterator iterCamels = fieldCamels.begin();

	while(iterMarket != game.field.market.end())
	{
		if(*iterMarket.Card::getIsCamel())
		{
			iterCamels = fieldCamels.insert(iterCamels, *iterMarket);
			// do I need to increment iterCamels???
		}
		iterMarket++;	
	}

	type = "camels";
	if(fieldCamels.size() == 0)
	{
		validMove = false;
		// throw exception??
		return;
	}
	else
		validMove = true;
}

Move::Move(Field * f, OList<Card *> & handRef, vector<int> cardsToSell); // use of this constructor means: "sell"
{
	field = f;
	int cardIndex; // pre-declaration

	oListIterator<Card *> iterHand = handRef.begin();
	vector<int>::iterator iterSellCards = cardsToSell.begin();

	while(iterSellCards != cardsToSell.end())
	{
		cardIndex = *iterSellCards;

		while(--cardIndex != 0 && iterHand != handRef.end())
		{
			iterHand++;
			cardIndex--;
		}
		if(iterHand != handRef.end())
			sell.insert(*iterHand);
		// else throw exception??

		iterHand = handRef.begin(); // reset iterHand to beginning of OList hand
		iterSellCards++;
	}

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


}

Move::Move(Field * f, OList<Card *> & handRef, vector<int>, vector<char>); // use of this constructor means: "exchange"
{
	field = f;
	player = p;
}

Move::Move(Field * f, OList<Card *> & handRef, char); // use of this constructor means: "take"
{
	field = f;
	player = p;
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
