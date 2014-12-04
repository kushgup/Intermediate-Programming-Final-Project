/*
This file contains all the function definitions for Player
*/

#include "Player.h"
#include "Field.h"

int Player::countPts() const {

	int points = 0;
	vector<Token *>::const_iterator iter;
	for (iter = tokens.begin(); iter != tokens.end(); iter++)
		points += **iter.getValue();
	return points;
}

void Player::takeCamels() {

	//assumes that the field has been checked by "move" object already
	vector<Token *>::const_iterator iter;
	for (iter = market.begin(); iter != market.end(); iter++)
		if(**iter.getIsCamel()) {
			herd.push_back(*iter); //add to hand
			//delete from market
			//add card to market from deck
		}
}

void Player::takeCard(Card * to_take) {

	//assumes that the field has been checked by "move" object already
	vector<Token *>::const_iterator iter;
	for (iter = market.begin(); iter != market.end(); iter++)
		if(*iter == to_take) {
			//add to hand
			//delete from market/
			//add card to market from deck
		}
}

void Player::exchange(vector<Card *> take, vector<Card *> give) {

	//assumes that the field has been checked by "move" object already
	//

}

void Player::sellCards(vector<Card *> sell) {

	//assumes that the field has been checked by "move" object already
	//iterate through the hand to find the cards to sell
	//delete them from the hand but not from the deck
	//add tokens to the player hand

}
