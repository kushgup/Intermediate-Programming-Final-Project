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

void Game::initPlayers() {
    //////////////// get number of human / AI players ////////////////
    int numPlayers;
    cout << "Enter how many human players will be playing (0 - 2)" << endl;
    cin >> numPlayers;
    // try catch potentially

    //////////////// initialize players ////////////////
    int i=0;
    string name, temp;
    while(numPlayers--) // create human players
    {
        cout << "Enter player name" << endl;
        cin >> name;
        playersInGame[i++] = new PlayerHuman(name, &field, &bank);
    }
    while(i<2) // create remaining AI players
    {
        itoa(i, temp, 10);
        name = "AI Player" + temp;
        playersInGame[i++] = new PlayerComp(name, &field, &bank);

    }

    //////////////// deal initial player hands ////////////////
    for(i=0; i<2; i++)
    {
        for(int j=0; j<5; j++)
        {
            playersInGame[i].hand.i
            player1Hand.push_back(deck.Deck::dealCard());
            player2Hand.push_back(deck.Deck::dealCard());
        }
    }

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

