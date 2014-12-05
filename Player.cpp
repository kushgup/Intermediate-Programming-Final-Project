/*
This file contains all the function definitions for Player
*/

#include "Player.h"
#include "Field.h"
#include <iostream>

using std::cout; using std::endl;

int Player::countPts() const {

	int points = 0;
	vector<Token *>::const_iterator iter;
	for (iter = tokens.begin(); iter != tokens.end(); iter++)
		points += **iter.getValue();
	return points;
}

void Player::printHand() const {

	cout << name <<  << endl;
	OList<Card *>::const_iterator iter;
	int i = 1;
	for(iter = hand.begin(); iter != hand.end(); iter++)
		cout << i << ") " << (**iter).getIdentifier() << endl;
	cout << "Camels: " << herd.size() << endl;
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

void Player::takeCard(Move to_make) {

	//assumes that the field has been checked by "move" object already
	vector<Token *>::const_iterator iter;
	for (iter = market.begin(); iter != market.end(); iter++)
		if(**iter == *to_take) {
			//add to hand
			//delete from market
			//add card to market from deck
		}
}

void Player::exchange(Move to_make) {

	//assumes that the field has been checked by "move" object already
	//

}

void Player::sellCards(Move to_make) {

	//assumes that the field has been checked by "move" object already
	//iterate through the hand to find the cards to sell
	//delete them from the hand but not from the deck
	//add tokens to the player hand

}
