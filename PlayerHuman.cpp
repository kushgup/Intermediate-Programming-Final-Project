/*
This file contains all the function definitions for the Human Player
*/

#include "PlayerHuman.h"

void PlayerHuman::makeMove() {

	printHand();
	cout << "a) take camels" << endl;
	cout << "b) take single card" << endl;
	cout << "c) exchange cards" << endl;
	cout << "d) sell cards" << endl;
	cout << "Select a move: ";
	char ch;
	//big try catch block to do exception handling
	//try {
		//have text-based GUI and construct move objects, then call individual functions checking valid first
		cin >> ch;
		if(ch == 'a') {
			Move next(game_field, hand);
			takeCamels(next);
		} else if(ch == 'b') {
			cout << "Which card to take? ";
			cin >> ch;
			Move next(game_field, hand, ch);
			takeCard(next);
		} else if(ch == 'c') {
			vector<int> mkt_take;
			vector<char> hand_return;
			int num_camels = 0;
			while(cin >> ch) {
				if(isdigit(ch))
					mkt_take.push_back(ch);
				else if(ch >= 'A' && ch <= 'z')
					hand_return.push_back(ch);
				else
					if(ch == '?')
						num_camels++;
			}
		} else if(ch == 'd') {

		} else
			//throw exc;
	//} catch {

	//}
}
