#include <time.h>

#include "Game.h"
#include "PlayerComp.h"
#include "PlayerHuman.h"

#define PLYR_VS_AI 1
#define PLYR_VS_PLYR 2

using std::cout;
using std::cin;
using std::endl;
using std::string;


Game::Game() {
    cout << "Choose type of game \n1) human v. human\n2) human v. computer\n" << endl;
    int typeofPlayersinGame;
    do
    {
        cin >> typeofPlayersinGame;
    }
    while (typeofPlayersinGame != 1 || typeofPlayersinGame != 2);

    //create field
    field = * new Field();
    //create bank
    bank = *new Bank();
    switch (typeofPlayersinGame){
        case PLYR_VS_PLYR:
            {
                for (int i = 0; i < 2; i++) {
                    cout << "Enter player (" << i << ") name: ";
                    string name;
                    cin >> name;
                    player[i] = new PlayerHuman(name, &field, &bank);
                }
                break;
            }
        case PLYR_VS_AI:
            {
                cout << "Enter player (0) name: ";
                string name0;
                cin >> name0;
                player[0] = new PlayerHuman(name0, &field, &bank);

                cout << "Enter player (0) name: ";
                cin >> name0;
                //player[1] = new PlayerComp(name0, &field, &bank);
                break;
            }
        default:
            cout << "ERROR!" << endl;

        }
    //Game::setPlayers(typeofPlayersinGame);


}

/*
Game::Game(Game& other) {

}
*/
/*
Game::~Game() {

}
*/

void Game::setPlayers(int typeofPlayersinGame) {
    /*switch (typeofPlayersinGame){
        case PLYR_VS_PLYR:
            {
                for (int i = 0; i < 2; i++) {
                    cout << "Enter player (" << i << ") name: ";
                    string name;
                    cin >> name;
                    player[i] = * new PlayerHuman(name, *field, *bank);
                }
                break;
            }
        case PLYR_VS_AI:
            {
                cout << "Enter player (0) name: ";
                string name0;
                cin >> name0;
                player[0] = * new PlayerHuman(name, *field, *bank);

                cout << "Enter player (0) name: ";
                string name0;
                cin >> name0;
                player[1] = * new PlayerComp(name, *field, *bank);
                break;
            }
        default:
            cout << "ERROR!" << endl;

        }
        //cout << "Enter name: "*/
}
void Game::printBoard() {
    bank.Bank::printBank();
    field.Field::printField();
}

bool Game::roundIsOver(){
    int CardsLeftinDeck = 55 - field.getDeck()->getPlaceInDeck();
    if (CardsLeftinDeck == 0){
        return true;
    }

    int depletedTokens = bank.Bank::isDepleted();

    if(depletedTokens >= 3){
        return true;
    }
    return false;
}

bool Game::gameOver()
{
    if (player[0]->Player::countSeals() == 2) {
        Game::setWinner(0);
        return true;
    }
    if (player[1]->Player::countSeals()== 2){
        Game::setWinner(1);
        return true;
    }
    return false;
}

Player & Game::setWinner(int x)
{
    return *player[x];
}

void Game::playGame()
{
    while(!Game::gameOver())
    {
        cout << "Lets start the round of Jaipur" << endl;
        field.Field::restoreDeck();
        bank.Bank::refillBank();

        while (!roundIsOver){

        }

    }

}

