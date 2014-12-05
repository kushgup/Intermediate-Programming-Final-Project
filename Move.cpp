#include "Move.h"
#include "Game.h"
#include "Field.h"
#include "OListIterator.h"
#include "Player.h"

Move::Move(Field * f, Player * p); // use of this constructor means: "camels"
{
	field = f;
	player = p;

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
		validMove = false;
	else
		validMove = true;
}

Move::Move(Field * f, Player * p, vector<int> cardsToSell); // use of this constructor means: "sell"
{
	field = f;
	player = p;

	oListIterator<Card *> iterHand = p.hand.begin();
	vector<int>::iterator iterSellCards = cardsToSell.begin();

	while(iterSellCards != cardsToSell.end())
	{
		int cardIndex = *iterSellCards;

		while()

		iterSellCards++;
	}

}

Move::Move(Field * f, Player * p, vector<int>, vector<char>); // use of this constructor means: "exchange"
{
	field = f;
	player = p;
}

Move::Move(Field * f, Player * p, char); // use of this constructor means: "take"
{
	field = f;
	player = p;
}