#include "PlayerComp.h"

void PlayerComp::makeMove() {

	//make four different moves and just pick one that is valid
	Move next1(game_field); //takes camels
	Move next2(game_field, hand, 'a'); //take 1st card in market
	vector<int> a;
	vector<char> b;
	a.push_back(1);
	a.push_back(2);
	b.push_back('a');
	b.push_back('b');
	Move next3(game_field, hand, a, b, 0, herd); //exchange first two cards in market for first two cards in hand
	vector<int> c;
	c.push_back(1);
	Move next4(game_field, hand, c); //sell first card in hand
	if()

	else if ()
	else if ()
	else if(next1.isValid())


	return 0;
}
