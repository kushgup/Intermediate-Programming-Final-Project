/*
This file contains all the function definitions for the Human Player
*/

#include "PlayerHuman.h"

void PlayerHuman::makeMove() {

	printHand();
	vector<int> mkt_take;
	vector<char> hand_return;
	int num_camels;
	char c;
	while(cin >> c) {
		if(c.isDigit())
			mkt_take.push_back(c);
		else if(c >= 'A' && c <= 'z')
			hand_return.push_back(c);
		else
			if(c == '?')
				num_camels++;
	}

}
