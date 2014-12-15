#include "PlayerComp.h"
#include <ctime>
#include <cstdlib>
#include <map>
using namespace std;

void PlayerComp::makeMove() {
    
    srand(time(NULL));
    int hSize = Player::handSize();
    bool incorrectMove = true;
    
    while (incorrectMove)
    {
    
        //This AI is really dumb because i am really dumb...EJ
        try {
            vector<int> to_sell;
            int randomPick = rand()% 3;
            
            if (hSize == 6){
                int handCard;
                handCard = (rand() % hSize) + 1;
                Move next(game_field, hand, handCard);
                sellCards(next);
                incorrectMove = false;
            }
            else if (hSize == 1)
            {
                int MarketCard;
                MarketCard = rand() % 5;
                char TakeCard = 'a' + MarketCard;
                to_sell.push_back(TakeCard);
                Move next(hand, to_sell);
                takeCard(next);
                incorrectMove = false;
            }
            else if (randomPick == 0)
            {
                Move next(game_field);
                takeCamels(next);
                incorrectMove = false;
            }
            else if (randomPick == 1)
            {
                int handCard;
                handCard = (rand() % hSize) + 1;
                Move next(game_field, hand, handCard);
                sellCards(next);
                incorrectMove = false;
            }
            else
            {
                int MarketCard;
                MarketCard = rand() % 5;
                char TakeCard = 'a' + MarketCard;
                to_sell.push_back(TakeCard);
                Move next(hand, to_sell);
                takeCard(next);
                incorrectMove = false;
            }
        }
        catch(exception& e){}
    }
}