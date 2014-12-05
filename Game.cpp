#include <time.h>

#include "Game.h"
#define PLYR_VS_AI 1
#define PLYR_VS_PLYR 2

using std::cout;
using std::cin;
using std::endl;
using std::string;


Game::Game() {
    cout << "Choose type of game \n1) human v. human\n2) human v. computer\n" << endl;
    int typeofPlayersinGame;
    cin >> typeofPlayersinGame;
    while (typeofPlayersinGame != 1 || typeofPlayersinGame != 2)
    {
        cout << "Invalid choice" << endl;
        cin >> typeofPlayersinGame;
    }

    //create field
    field = * new Field();

    //Game::setPlayers(typeofPlayersinGame);

    //create bank
    bank = *new Bank();


}

/*
Game::Game(Game& other) {

}
*/
/*
Game::~Game() {

}
*/
/*
void Game::setPlayers(int typeofPlayersinGame) {
    switch (typeofPlayersinGame){
        case PLYR_VS_PLYR:
            {
                for (int i = 0; i < 2; i++) {
                    cout << "Enter player (" << i << ") name: ";
                    string name;
                    cin >> name;
                    player[i] = * new PlayerHuman(name, *field);
                }
                break;
            }
        case PLYR_VS_AI:
            {
                cout << "Enter player (0) name: ";
                string name0;
                cin >> name0;
                player[0] = * new PlayerHuman(name, *field);

                cout << "Enter player (0) name: ";
                string name0;
                cin >> name0;
                player[1] = * new PlayerAI(name, *field);
                break;
            }
        default:
            cout << "ERROR!" << endl;

        }
        //cout << "Enter name: "
}
void Game::printBoard() {
    bank.Bank::printBank();
    field.Field::printField();
}
*/
bool Game::roundIsOver(){
    int CardsLeftinDeck = 55 - field.getDeck()->getPlaceInDeck();
    if (CardsLeftinDeck == 0){
        return true;
    }

    int depletedTokens = bank.Bank::isDeplited();

    if(depletedTokens >= 3){
        return true;
    }
}



