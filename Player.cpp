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


}

void Player::takeCard(Card * to_take) {


}

void Player::exchange(Card ) {


}

void Player::sellCards() {


}
