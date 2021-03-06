#include "Field.h"
#include <cstdio>
#include <iostream>

using std::cout;
using std::endl;

Field::Field()
{
    refillMarket();
}

void Field::printField() const
{
    deck.printDeck();
    cout << endl;
    cout << "Market ********************************************" <<endl;
    market.at(0)->printCard();
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
}

void Field::resetForRound() {

    deck = Deck();
    market.clear();
}
