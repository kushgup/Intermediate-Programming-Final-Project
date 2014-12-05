#include "Deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Card.h"
#include <array>
#include <time.h>

Deck::Deck()
{
    for(int i = 0; i < 11; i++)
    {
        deckTobeshuffled[i] = *new Card("Camel");
        //deck[i].setIdentifier("Camel");
    }
    for(int i = 11; i< 21; i++)
    {
        deckTobeshuffled[i] = *new Card("Paper");
        //deck[i].setIdentifier("Paper");
    }
    for(int i = 21; i< 29; i++)
    {
        deckTobeshuffled[i] = *new Card("Spice");
        //deck[i].setIdentifier("Spice");
    }
    for(int i = 29; i< 37; i++)
    {
        deckTobeshuffled[i] = *new Card("Cloth");
        //deck[i].setIdentifier("Cloth");
    }
    for(int i = 37; i< 43; i++)
    {
        deckTobeshuffled[i] = *new Card("Silver");
    }
    for(int i = 43; i< 49; i++)
    {
        deckTobeshuffled[i] = *new Card("Gold");
    }
    for(int i = 49; i<= 52; i++)
    {
        deckTobeshuffled[i] = *new Card("Diamonds");
    }
    for(int i =0; i<3; i++)
    {
        startCamels[i] = *new Card ("Camel");
    }
    startCamels[0].Card::setPandaCamel();
    shuffle();

    for(int j = 0; j<3; j++)
    {
        deckForGame[j] = startCamels[j];
    }
    for(int j =3; j<55; j++)
    {
        deckForGame[j] = deckTobeshuffled[j];
    }

    placeinDeck = 0;
}
/*
Deck::~Deck()
{
    for(int i = 0; i< 55; i++)
    {
        delete deckForGame[i];
    }
    delete [] deckForGame;
    for(int i = 0; i< 52; i++)
    {
        delete deckTobeshuffled[i];
    }
    for(int i = 0; i< 3; i++)
    {
        delete startCamels[i];
    }
}
*/
void Deck::shuffle()
{
    int seed;

    time_t t;
    seed = (int) time(&t);

    srand((unsigned) seed);


    for(int i = 0; i< 52; i++)
    {
        int s = rand() % 52;
        swap(i, s);
    }
}

void Deck::swap(int a, int b)
{
    Card temp = deckTobeshuffled[a];
    deckTobeshuffled[a]=deckTobeshuffled[b];
    deckTobeshuffled[b] = temp;
}

void Deck::printDeck()
{
    cout << "Deck:\t\t";
    char blackSquare = '\u25A0';
    for (int i = 1; i<=MAXCARDSINDECK-placeinDeck; i++)
    {
        cout << "# ";
        if (i % 15 == 0)
        {
            cout << endl;
            cout << "\t\t";
        }

    }
    cout << endl;
}

Card * Deck::dealCard()
{
    if (placeinDeck == 55)
        return nullptr;
    Card * temp = &deckForGame[placeinDeck];
    placeinDeck++;
    return temp;
}





