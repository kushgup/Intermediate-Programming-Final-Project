/*
This file contains all the function definitions for the Human Player
*/

#include "PlayerHuman.h"
#include <exception>
#include <limits>
#include <string>
using namespace std;


void PlayerHuman::makeMove(){

	printHand();
	cout << "a) take camels" << endl;
	cout << "b) take single card" << endl;
	cout << "c) exchange cards" << endl;
	cout << "d) sell cards" << endl;
	cout << "Select a move: ";
	string str;
    char ch;

	//big try catch block to do exception handling
	//try {
		//have text-based GUI and construct move objects, then call individual functions checking valid first
    bool incorrectMoveOption = true;
    while (incorrectMoveOption)
    {
        try
        {
            cin >> str;
            if( str.length() > 1) throw 15;
            ch = str.at(0);

    		if(ch == 'a')
    		{

                /* WORK IN PROGRESS
                */
                Move next(game_field);
                   if(next.isValid())
                      takeCamels(next);
                    else
                        throw 20;
    		}

    		else if(ch == 'b')
    		{
    			cout << "Which card to take? ";
    			cin >> ch;
                bool tookAValidCard = true;
                while (tookAValidCard)
                {
                    if(ch == 'a' || ch == 'b' || ch == 'c' || ch == 'd' || ch == 'e')
                    {
                        tookAValidCard = false;
                    }
                    else
                    {
                        cout << "That isn't a card you can take" << endl;
                        cout << "Which card to take? ";
                        cin >> ch;
                    }
                        
                }
    			Move next(game_field, hand, ch);
    			if(next.isValid())
                    takeCard(next);
                incorrectMoveOption = false;
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
                    if(in_char >= 'a' && in_char <= 'e')
                        mkt_take.push_back(in_char);
                    else
                        cout << "Invalid Character! Enter a character between 'a' and 'e' to select a Card" << endl; // exception?
                    cin >> in_char;
                }

                cout << "-Exchange in hand (9 to finish): " << endl;
                cout.flush();
                int in_hand;
                cin >> in_hand;
                while (in_hand != 9) {
                    if(in_char >= 1 && in_char <= hand.size())
                        hand_return.push_back(in_hand);
                    else
                        cout << "Invalid Character! Enter a number between '1' and '" << hand.size() << "' to select a Card" << endl; // exception?
                    cin >> in_hand;
                }

    			Move next(game_field, hand, hand_return, mkt_take, num_camels, herd);
    			if(next.isValid())
                    exchange(next);
                incorrectMoveOption = false;
    		}

    		else if(ch == 'd')
    		{
    			cout << "Selected d" << endl;
    			vector<int> to_sell;

                cout << "-Cards in hand to sell (9 to finish): " << endl;
                cout.flush();
                int in_hand;
                int numCardsinHand = this->Player::handSize();
                cin >> in_hand;
                while(std::cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Bad entry.  Enter a NUMBER: ";
                    cin >> in_hand;
                }
                while (in_hand != 9)
                {
                    if (in_hand > 0 && in_hand <= numCardsinHand)
                    {
                        to_sell.push_back(in_hand);
                    }
                    else
                    {
                        cout << "You can't sell that card! pick another or press 9 to finish: ";
                    }
                    cin >> in_hand;
                    while(std::cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Bad entry.  Enter a NUMBER: ";
                        cin >> in_hand;
                    }
                }

                for( std::vector<int>::const_iterator i = to_sell.begin(); i != to_sell.end(); ++i)
                    std::cout << *i << ' ';
                cout << endl;
                
                try{
                    Move next(hand, to_sell);
                    if(next.isValid())
                        sellCards(next);
                    else
                        throw 20;
                    incorrectMoveOption = false;
                }
                catch (int e)
                {
                    cout << "You can's sell those cards together!!!" <<endl;
                    cout << "a) take camels" << endl;
                    cout << "b) take single card" << endl;
                    cout << "c) exchange cards" << endl;
                    cout << "d) sell cards" << endl;
                    cout << "Select a move: ";
                }
    		}

    		else throw 20;

            incorrectMoveOption = false;
        }
        catch(int e)
        {
            cout << "You didn't do it properly!!" << endl;
            cout << endl;
            cout << "a) take camels" << endl;
            cout << "b) take single card" << endl;
            cout << "c) exchange cards" << endl;
            cout << "d) sell cards" << endl;
            cout << "Select a move: ";

            // keep incorrectMoveOption = true
        }
    }
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
