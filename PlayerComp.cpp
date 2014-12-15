#include "PlayerComp.h"
#include <ctime>
#include <cstdlib>
#include <map>
using namespace std;

void PlayerComp::makeMove() {
    
    srand(time(NULL));
    int hSize = Player::handSize();
    bool incorrectMove = true;
    
    printHand();
    
    while (incorrectMove)
    {
    
        //This AI is really dumb because i am really dumb...EJ
        try {
            vector<int> to_sell;
            int randomPick = rand()% 3;
            
            if (hSize == 6) //SELL
            {
                int handCard;
                handCard = (rand() % hSize) + 1;
                int numCardsSelling = (rand() % 2) +1;
                for (int j= 0; j < numCardsSelling; j++){
                    to_sell.push_back(handCard+j);
                }
                Move next(hand, to_sell);
                sellCards(next);
                incorrectMove = false;
                cout << "Computer Sold a Card!" << endl;
            }
            else if (hSize == 1)    //TAKE ONE CARD
            {
                int MarketCard;
                MarketCard = rand() % 5;
                char TakeCard = 'a' + MarketCard;
                Move next(game_field, hand, TakeCard);
                takeCard(next);
                incorrectMove = false;
                cout << "Computer Took a Card!" << endl;
            }
            else if (randomPick == 0) // TAKE CAMEL
            {
                Move next(game_field);
                takeCamels(next);
                incorrectMove = false;
                cout << "Computer Took the Camels:" <<endl;
            }
            else if (randomPick == 1) //SELL
            {
                int handCard;
                handCard = (rand() % hSize) + 1;
                to_sell.push_back(handCard);
                Move next(hand, to_sell);
                sellCards(next);
                incorrectMove = false;
                cout << "Computer Sold a Card!" << endl;
            }
            else        //TAKE ONE CARD
            {
                int MarketCard;
                MarketCard = rand() % 5;
                char TakeCard = 'a' + MarketCard;
                Move next(game_field, hand, TakeCard);
                takeCard(next);
                incorrectMove = false;
                cout << "Computer Took a Card!" << endl;
            }
        }
        catch(exception& e){
            cout << "Silly Computer you can't make that move" << endl;
        }
    }
}