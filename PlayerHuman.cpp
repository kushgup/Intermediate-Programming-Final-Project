/*
This file contains all the function definitions for the Human Player
*/

#include "PlayerHuman.h"
#include <exception>
#include <limits>
#include <string>

void PlayerHuman::makeMove(){

	printHand();
    
    bool incorrectMoveOption = true;
    while (incorrectMoveOption)
    {
        cout << "a) take camels" << endl;
        cout << "b) take single card" << endl;
        cout << "c) exchange cards" << endl;
        cout << "d) sell cards" << endl;
        cout << "Select a move: ";

        //~~~~~~~~~~~~ Selecting Move Properly ~~~~~~~~~~~~~~//
        string str;
        char ch;
        bool invalidInput = true;
        while(invalidInput)
        {
            try
            {
                cin >> str;
                if( str.length() > 1)
                    throw inputTooLongException();
                ch = str.at(0);

                if(!(ch >= 'a' && ch <= 'd'))
                    throw invalidInitialSelectionException();

                invalidInput = false;
            }
            catch(exception& e)
            {
                cout << e.what() << endl;
            }
        }

        //~~~~~~~~~~~~ Executing Move ~~~~~~~~~~~~~~//
        try
        {
    		if(ch == 'a') // THIS IS DONE!
    		{
                cout << "Taking Camels..." << endl;
                Move next(game_field);
                takeCamels(next);
                incorrectMoveOption = false;
    		}

    		else if(ch == 'b') // THIS IS DONE!
    		{
    			cout << "Taking a Card... Which card to take?" << endl;

                // get char corresponding to Market card. If invalid, throw exception 
                char card_ch;
    			cin >> card_ch;
                if(card_ch != 'a' && card_ch != 'b' && card_ch != 'c' && card_ch != 'd' && card_ch != 'e')
                    throw invalidInputforMarketException();

    			Move next(game_field, hand, card_ch);
                takeCard(next);
                incorrectMoveOption = false;
    		}

    		else if(ch == 'c')
    		{
                cout << "Exchanging Now..." << endl;

    			vector<char> mkt_take;
    			vector<int> hand_return;
                int num_camels = 0;

                cout << "-Exchange in market (ENTER between entries; q to finish): " << endl;
                char in_char;
                cin >> in_char;
                while (in_char != 'q') {
                    if(!(in_char >= 'a' && in_char <= 'e'))
                        throw invalidInputforMarketException();

                    mkt_take.push_back(in_char);
                    cin >> in_char;
                }

                cout << "-Exchange in hand (ENTER between entries; 9 to finish): " << endl;
                int in_hand;
                cin >> in_hand;
                while (in_hand != 9) {
                    if(!(in_hand >= 1 && in_hand <= hand.size()))
                        throw invalidInputforHandException();

                    hand_return.push_back(in_hand);
                    cin >> in_hand;
                }

                cout << "How many Camels from Herd to Give" << endl;
                cin >> num_camels;
                if( num_camels < 0 || num_camels > (int) herd.size())
                    throw invalidNumCamelsToGive();

                //order the vector of chars in mkt_take to make sure that the end iterators won't get messed up
                if(mkt_take.size() > 1) // idiot proofing our code
                {
    			    char temp;
    			    vector<char>::iterator i = mkt_take.end() - 1, j = mkt_take.begin();
    			    while (i != j) {
    			        if(*(i - 1) > *i) {
    			            temp = *(i - 1);
    			            *(i - 1) = *i;
    			            *i = temp;
    			        }
    			        i--;
    			    }
                }

    			Move next(game_field, hand, hand_return, mkt_take, num_camels, herd);
                exchange(next);
                incorrectMoveOption = false;
    		}

    		else if(ch == 'd')
    		{
    			cout << "Selling Cards!" << endl;
    			vector<int> to_sell;

                cout << "-Cards in hand to sell (9 to finish): " << endl;
                int in_hand;
                cin >> in_hand;
                /* What is this.... ?
                int numCardsinHand = this->Player::handSize();
                while(std::cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Bad entry.  Enter a NUMBER: ";
                    cin >> in_hand;
                }
                */
                while (in_hand != 9)
                {
                    if(!(in_hand >= 1 && in_hand <= hand.size()))
                        throw invalidInputforHandException();

                    to_sell.push_back(in_hand);

                    cin >> in_hand;

                    /*
                    while(std::cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Bad entry.  Enter a NUMBER: ";
                        cin >> in_hand;
                    }
                    */
                }

                /* Delete this??
                for( std::vector<int>::const_iterator i = to_sell.begin(); i != to_sell.end(); ++i)
                    std::cout << *i << ' ';
                cout << endl;
                */
                
                Move next(hand, to_sell);
                sellCards(next);
                incorrectMoveOption = false;
    		}

        }
        catch(exception& e)
        {
            cout << e.what() << endl;
        }
    }
}
