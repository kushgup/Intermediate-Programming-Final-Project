#include "Game.h"
#include <ctime>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string;

Game::Game(): roundNum(1), playerWinnerIndex(0) {
    bool init_passed = false;
    while (!init_passed)
    {
        try {
            initPlayers();
            init_passed = true;
        } catch (std::exception &e) {
            cout << "# players must be btw 0 and 2!" << endl;
        }
    }


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
    if (numPlayers < 0 || numPlayers > 2) {
            throw std::range_error("must be btw 0 and 2!");
    }
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
    Card * temp;
    for(i = 0; i < 2; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            temp = field.deck.dealCard();
            if(temp->getIsCamel())
                // do shit
                (*players[i]).herd.push_back(temp);
            else
                (*players[i]).hand.insert(temp);
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
            printBoard();
            for(int k = 0; k < 55; k++)
            {
                cout << k << ": " << field.deck.deckTobeshuffled[k].getIdentifier() << endl;
            }
            (*players[playerWinnerIndex]).makeMove();
            field.refillMarket();
            printBoard();
            (*players[(playerWinnerIndex + 1) % 2]).makeMove();
            field.refillMarket();
        }
        field.restoreDeck();
        bank.refillBank();

        //update roundnumber and playerwinnerindex, compute who gets a seal
        calculateWinner(); // assign camel token and calculate who wins. Give seal to winner and update playerWinnerIndex
        roundNum++;

        // empty player hands and reset
        for(int i = 0; i < 2; i++)
        {
            players[i]->resetForRound();
        }
    }

}

void Game::calculateWinner() // assign camel token and calculate who wins. Give seal to winner and update playerWinnerIndex
{
    if((*players[0]).numCamels() > (*players[1]).numCamels() )
    {
        (*players[0]).tokens.push_back(bank.getCamelToken());
    }
    else if((*players[1]).numCamels() > (*players[0]).numCamels() )
    {
        (*players[1]).tokens.push_back(bank.getCamelToken());
    }
    else // tie for # of camels
    {
        //PANDA CAMEL
    }
    if((*players[0]).countPts() > (*players[1]).countPts())
    {
        playerWinnerIndex = 0;
        players[0]->seals.push_back(bank.takeSeal());
    }
    else if((*players[1]).countPts() > (*players[0]).countPts()) {
        playerWinnerIndex = 1;
        players[1]->seals.push_back(bank.takeSeal());
    }
    else {
        //TIE
    }

}
