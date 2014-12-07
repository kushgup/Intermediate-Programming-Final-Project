/*
This file contains all the function definitions for the Human Player
*/

#include "PlayerHuman.h"

void PlayerHuman::makeMove(){

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

            cout << "-Exchange in market (q to finish): " << endl;
            cout.flush();
            char in_char;
            cin >> in_char;
            while (in_char != 'q') {
                mkt_take.push_back(in_char);
                cin >> in_char;
            }

            cout << "-Exchange in hand (9 to finish): " << endl;
            cout.flush();
            int in_hand;
            cin >> in_hand;
            while (in_hand != 9) {
                hand_return.push_back(in_hand);
                cin >> in_hand;
            }

            for( std::vector<char>::const_iterator i = mkt_take.begin(); i != mkt_take.end(); ++i)
                std::cout << *i << ' ';
            for( std::vector<int>::const_iterator i = hand_return.begin(); i != hand_return.end(); ++i)
                std::cout << *i << ' ';
            cout << endl;

			Move next(game_field, hand, hand_return, mkt_take, num_camels, herd);
			if(next.isValid())
                exchange(next);
		}

		else if(ch == 'd')
		{
			cout << "Selected d" << endl;
			vector<int> to_sell;

            cout << "-Cards in hand to sell (9 to finish): " << endl;
            cout.flush();
            int in_hand;
            cin >> in_hand;
            while (in_hand != 9) {
                to_sell.push_back(in_hand);
                cin >> in_hand;
            }

            for( std::vector<int>::const_iterator i = to_sell.begin(); i != to_sell.end(); ++i)
                std::cout << *i << ' ';
            cout << endl;

			Move next(hand, to_sell);
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
