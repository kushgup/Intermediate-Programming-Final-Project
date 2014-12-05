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
					mkt_take.push_back((int) ch);
				else if(ch >= 'A' && ch <= 'z')
					hand_return.push_back(ch);
				else
					if(ch == '?')
						num_camels++;
			}
			Move next(game_field, hand, mkt_take, hand_return, num_camels, herd);
			exchange(next);
		} else if(ch == 'd') {
			vector<int> to_sell;
			while(cin >> ch)
				to_sell.push_back((int) ch);
			Move next(game_field, hand, to_sell);			
			sellCards(next);
		} else
			cout << "you didn't do it properly!!" << endl; //this line should be replaced with exception handling
			//throw exc;
	//} catch {

	//}
}
