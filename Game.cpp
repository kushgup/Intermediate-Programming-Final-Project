#include "Game.h"
#include <ctime>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string;

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

    int i = 0;
    string name;
    while(numPlayers--) // create human players
    {
        cout << "Enter player name" << endl;
        cin >> name;
        players[i++] = new PlayerHuman(name, &field, &bank);

    }
    while(i < 2) // create remaining AI players
    {
        //char ch = i;
        //string str = ch;
        name = "AI Player";// + str;
        players[i++] = new PlayerComp(name, &field, &bank);
    }

    //deal initial player hands
    for(i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
          (*players[i]).hand.insert(field.deck.dealCard());
        }
    }
}

void Game::printBoard() {
    bank.printBank();
    field.printField();
}

bool Game::roundIsOver(){

    if((55 - field.deck.getPlaceInDeck()) == 0 || bank.isDepleted() >= 3) //check if deck is empty
        return true;
    return false;
}

bool Game::gameOver()
{
    if ((*players[0]).countSeals() == 2) {
        //setWinner(0);
        return true;
    }
    if ((*players[1]).countSeals() == 2) {
        //setWinner(1);
        return true;
    }
    return false;
}

void Game::playGame()
{
    while(!gameOver())
    {
        cout << "Lets start the round of Jaipur" << endl;
        while (!roundIsOver()){
            (*players[playerWinnerIndex]).makeMove();
            field.refillMarket();
            (*players[(playerWinnerIndex + 1) % 2]).makeMove();
            field.refillMarket();
        }
        field.restoreDeck();
        bank.refillBank();
        //update roundnumber and playerwinnerindex, compute who gets a seal
    }
}
