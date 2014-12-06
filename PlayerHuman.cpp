/*
This file contains all the function definitions for the Human Player
*/

#include "PlayerHuman.h"
#include "ctype.h" // <ctype.h>

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
		

		///////// if NOT using cin (using C-type functions instead) /////////
		char c_one, c_two;
		/////////////////////////////////////////////////////////////////////
		

		cin >> ch;
		if(ch == 'a')
		{
			Move next(game_field);
			if(next.isValid())
                takeCamels(next);
		}

		else if(ch == 'b')
		{
			cout << "Which card to take? ";
			cin >> ch;
			Move next(game_field, hand, ch);
			if(next.isValid())
                takeCard(next);
		}

		else if(ch == 'c')
		{
			vector<char> mkt_take;
			vector<int> hand_return;
			int num_camels = 0;

			while( isspace(c_one =getchar()) ); // c is the first non-whitespace character to be entered
			while(c_one != '\n' && c_one != EOF)
			{

				if(isdigit(c_one))
					hand_return.push_back((int) c_one);
				else if(c_one >= 'A' && c_one <= 'z')
					mkt_take.push_back(c_one);
				else if(c_one == '?')
						num_camels++;

				while( isspace(c_one =getchar()) ); // c is the first non-whitespace character to be entered

			}
			Move next(game_field, hand, hand_return, mkt_take, num_camels, herd);
			if(next.isValid())
                exchange(next);
		}

		else if(ch == 'd')
		{
			vector<int> to_sell;

			while( isspace(c_two =getchar()) ); // c is the first non-whitespace character to be entered
			while(c_two != '\n' && c_two != EOF)
			{
				if(isdigit(c_two))
					to_sell.push_back((int) c_two);

				while( isspace(c_one =getchar()) ); // c is the first non-whitespace character to be entered

			}
			Move next(game_field, hand, to_sell);
			if(next.isValid())
                sellCards(next);
		}

/*
		else if(ch == 'c')
		{
			vector<char> mkt_take;
			vector<int> hand_return;
			int num_camels = 0;
			while(cin >> ch && ch != 'q')
			{
				if(isdigit(ch))
					hand_return.push_back((int) ch);
				else if(ch >= 'A' && ch <= 'z')
					mkt_take.push_back(ch);
				else
					if(ch == '?')
						num_camels++;
			}
			Move next(game_field, hand, hand_return, mkt_take, num_camels, herd);
			if(next.isValid())
                exchange(next);
		}

		else if(ch == 'd')
		{
			vector<int> to_sell;
			while(cin >> ch && ch != 'q') {
                to_sell.push_back((int) ch);
			}
			Move next(game_field, hand, to_sell);
			if(next.isValid())
                sellCards(next);
		}
*/

		else
			cout << "you didn't do it properly!!" << endl; //this line should be replaced with exception handling
			//throw exc;
	//} catch {

	//}
}
