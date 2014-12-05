//
//  Field.cpp
//  pg7b
//
//  Created by Edmund Connor on 11/25/14.
//  Copyright (c) 2014 Edmund Connor. All rights reserved.
//

#include "Field.h"
#include <stdio.h>
#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;

Field::Field()
{
    for (int i =0; i<5; i++)
    {
        market.push_back(deck.dealCard());
    }
    for (int i =0; i<5; i++)
    {
        player1Hand.push_back(deck.dealCard());
        player2Hand.push_back(deck.dealCard());
    }
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

}
