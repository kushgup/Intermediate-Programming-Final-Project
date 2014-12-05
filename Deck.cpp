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

void Deck::shuffle()
{
    /** SEED TIME **/
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
    int cardsInDeck = sizeof(deckForGame)/sizeof(deckForGame[0]);
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

Card * Deck::dealCard()
{
    Card * temp = &deckForGame[placeinDeck];
    placeinDeck++;
    return temp;
}





