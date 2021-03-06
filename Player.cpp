/*
This file contains all the function definitions for Player
The different actions a player takes on their turn depend heavily on a "move" object for that turn that is constructed in makeMove()
*/

#include "Player.h"
#include <iomanip>

int Player::countPts() const {

	int points = 0;
	vector<Token *>::const_iterator iter;
	for (iter = tokens.begin(); iter != tokens.end(); iter++)
		points += (**iter).getValue();
	return points;
}

bool Player::hasPandaCamel()
{
    for (int i = 0; i < numCamels(); i++)
        if(herd[i]->Card::getIsPandaCamel())
            return true;
    return false;
}

void Player::resetForRound() {
	
    hand.clear();
    herd.clear();
    tokens.clear();
}

void Player::printHand() const {

	cout << std::setfill('*') << std::setw(50) << endl;
	cout << '\n' << name << "'s turn. You have " << countPts() << " points. Your hand:" << endl;
	int i = 1;
	for(OListIterator<Card*> iter = hand.begin(); iter != hand.end(); iter++)
		cout << i++ << ") " << (**iter).getIdentifier() << endl;
	cout << "Camels: " << herd.size() << '\n' << endl;
}

void Player::takeCamels(Move & to_make) {

	//assumes that the market has been checked by "move" object already... look for fieldCamels
	//reverse iterator so that delete, the other iterators aren't messed up
	vector<vector<Card *>::iterator>::reverse_iterator iter = to_make.fieldCamels.rbegin(), iter_end = to_make.fieldCamels.rend();
	while(iter != iter_end) {
		herd.push_back(**iter); //add to herd
		game_field->market.erase(*iter); //delete from market
		iter++; //update the iterator through the vector of iterators
	}
}

void Player::takeCard(Move & to_make) {

	//assumes that the market & hand has been checked by "move" object already... look for takeSingle
	hand.insertPointer(*to_make.takeSingle); //add to hand
	game_field->market.erase(to_make.takeSingle); //delete from market
}

void Player::exchange(Move & to_make) {

	//assumes that the market, hand, and/or herd has been checked by "move" object already... look for takeMult and returnMult
	//take cards first
	vector<vector<Card *>::iterator>::reverse_iterator takeIter = to_make.takeMult.rbegin(), takeIter_end = to_make.takeMult.rend();
	while(takeIter != takeIter_end) {
		hand.insertPointer(**takeIter); //add to hand
		game_field->market.erase(*takeIter); //delete from market
		takeIter++; //update the iterator through the vector of iterators
	}
	//return cards to the market second
	//need to deal with separate camel and hands!
	vector<OListIterator<Card *>>::iterator returnIter = to_make.returnMult.begin(), returnIter_end = to_make.returnMult.end();
	while(returnIter != returnIter_end) {
		game_field->market.push_back(**returnIter); //add to market
		hand.remove(**returnIter); //delete from hand
		returnIter++; //update the iterator through the vector of iterators
	}
	//refill market with camels if necessary
	for(int i = 0; i < to_make.num_camels_exchanged; i++) {
		game_field->market.push_back(herd.front()); //add camel to market
		herd.pop_back(); //delete last element in herd since they are all the same
	}
}

void Player::sellCards(Move & to_make) {

	//assumes that hand has been checked by "move" object already... look for sell
	//sell cards by deleting them, meanwhile adding tokens
	vector<OListIterator<Card *>>::iterator iter = to_make.sell.begin(), iter_end = to_make.sell.end();
	string type_sell = (***iter).getIdentifier();
	int how_many = to_make.sell.size();
	if(how_many >= 3 && !(*game_bank).isBonusDepleted(how_many))
		tokens.push_back((*game_bank).takeBonusToken(how_many)); //award the bonus token first, temporal order shouldn't matter
	while(iter != iter_end) {
		if(!(*game_bank).isGoodDepleted(type_sell)) //only award tokens while there are still tokens left
			tokens.push_back((*game_bank).takeTokenFromGoodTs(type_sell)); //award tokens
		hand.remove(**iter); //"sell card" by deleting from hand
		iter++;
	}
}
