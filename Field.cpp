#include "Field.h"
#include <stdio.h>
#include <iostream>
#include "Deck.h"
#include "Card.h"

using std::cout;
using std::endl;

Field::Field()
{
    for (int i =0; i<5; i++)
    {
        market.push_back(deck.dealCard());
    }

}

void Field::refillMarket()
{
    while(market.size() < 5)
        market.push_back(deck.dealCard());
}

void Field::printField()
{
    deck.Deck::printDeck();
    cout << endl;
    cout << "Market ********************************************"<<endl;
    market[0]->Card::printCard();
    cout << " ";
    market[1]->Card::printCard();
    cout << " ";
    market[2]->Card::printCard();
    cout << " ";
    market[3]->Card::printCard();
    cout << " ";
    market[4]->Card::printCard();
    cout << endl;
    char let = 'a';
    cout << "  ";
    for (int i= 0; i<5; i++)
    {
        cout<< let << "     ";
        let++;
    }
    cout << endl;
    cout << endl;

}
