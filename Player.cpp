/*
This file contains all the function definitions for Player
*/

#include "Player.h"
#include "Field.h"

int Player::countPts() {

	int points = 0;
	vector<Token *>::const_iterator iter;
	for (iter = tokens.begin(); iter!= tokens.end(); iter++)
		points += (*iter)->value;
	return points;
}

void Player::takeCamels() {


}

void Player::takeCard(Card * to_take) {


}

void Player::exchange() {


}

void Player::sellCards() {


}
