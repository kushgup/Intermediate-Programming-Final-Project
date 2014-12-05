#include "PlayerComp.h"
#include <ctime>

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

	if(!next1.isValid() && !next2.isValid() && !next3.isValid() && !next4.isValid()) {
		a.clear();
		b.clear();
		for(int i = 1; i < hand.size() - 1; i++) {
			a.push_back(i);
			for(int j = i + 1; j < hand.size(); j++) {
				a.push_back(j);
				next3 = Move(game_field, hand, a, b, 0, herd);
				a.pop_back();
			}
		}

	} else {
		srand(time(NULL));
		int x;
		bool y;
		while(!y) {
			x = rand() / (RAND_MAX / 4 + 1);
			switch (x) {
				case 0: 
					y = next1.isValid();
					break;
				case 1:
					y = next2.isValid();
					break;
				case 2:
					y = next3.isValid();
					break;
				case 3:
					y = next4.isValid();
					break;
			}
		}
		if(x == 0) takeCamels(next1);
		if(x == 1) takeCard(next2);
		if(x == 2) exchange(next3);
		if(x == 3) sellCards(next4);		
	}

}
