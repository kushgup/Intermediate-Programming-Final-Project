//
//  Deck.cpp
//  pg7b
//
//  Created by Edmund Connor on 11/23/14.
//  Copyright (c) 2014 Edmund Connor. All rights reserved.
//

#include "Deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Card.h"
#include <array>

Deck::Deck()
{
    for(int i = 0; i < 11; i++)
    {
        deck[i] = *new Card("Camel");
        //deck[i].setIdentifier("Camel");
    }
    for(int i = 11; i< 21; i++)
    {
        deck[i] = *new Card("Paper");
        //deck[i].setIdentifier("Paper");
    }
    for(int i = 21; i< 29; i++)
    {
        deck[i] = *new Card("Spice");
        //deck[i].setIdentifier("Spice");
    }
    for(int i = 29; i< 37; i++)
    {
        deck[i] = *new Card("Cloth");
        //deck[i].setIdentifier("Cloth");
    }
    for(int i = 37; i< 43; i++)
    {
        deck[i] = *new Card("Silver");
    }
    for(int i = 43; i< 49; i++)
    {
        deck[i] = *new Card("Gold");
    }
    for(int i = 49; i<= 52; i++)
    {
        deck[i] = *new Card("Diamonds");
    }
    for(int i =0; i<3; i++)
    {
        startCamels[i] = *new Card ("Camel");
    }
    shuffle();
}

Card Deck::getCardatIndex(int a)
{
    return deck[a];
}

void Deck::shuffle()
{
    for(int i = 0; i< 52; i++)
    {
        int s = rand() % 52;
        swap(i, s);
    }
}

void Deck::swap(int a, int b)
{
    Card temp = deck[a];
    deck[a]=deck[b];
    deck[b] = temp;
}

void Deck::printDeck()
{
    int cardsInDeck = sizeof(deck)/sizeof(deck[0]);
    cout << "Deck:\t";
    for (int i = 1; i<=cardsInDeck; i++)
    {
        cout << "• ";
        if (i % 15 == 0)
        {
            cout << endl;
            cout << "\t\t";
        }
        
    }
    cout << endl;
}







