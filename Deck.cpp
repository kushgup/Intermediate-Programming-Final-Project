#include "Deck.h"
#include <array>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using std::string;
using std::cout;
using std::endl;

Deck::Deck()
{
    int i;
    for(i = 0; i < 8; i++)
    {
        deckTobeshuffled[i] = Card("Camel");
    }
    for(; i < 18; i++)
    {
        deckTobeshuffled[i] = Card("Paper");
    }
    for(; i < 26; i++)
    {
        deckTobeshuffled[i] = Card("Spice");
    }
    for(; i < 34; i++)
    {
        deckTobeshuffled[i] = Card("Cloth");
    }
    for(; i < 40; i++)
    {
        deckTobeshuffled[i] = Card("Silver");
    }
    for(; i < 46; i++)
    {
        deckTobeshuffled[i] = Card("Gold");
    }
    for(; i < 52; i++)
    {
        deckTobeshuffled[i] = Card("Diamonds");
    }
    shuffle();

    for(; i < 55; i++)
    {
        deckTobeshuffled[i] = Card("Camel");
        if(i == 52)
            deckTobeshuffled[i].setPandaCamel();
        swap(i - 52, i);
    }

    //deckTobeshuffled[0].setPandaCamel();
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
    int num_cards = 52;
    //shuffle the deck by iterating 60 times, have a random number generator, swap cards in the deck
    int x, i;
    srand(time(NULL));
    for (i = 0; i < num_cards; i++) {
        x = rand() / (RAND_MAX / num_cards + 1);
        swap(i, x);

    }

}

void Deck::swap(int a, int b)
{
    Card temp ( deckTobeshuffled[a] );
    deckTobeshuffled[a] = deckTobeshuffled[b];
    deckTobeshuffled[b] = temp;
}

void Deck::printDeck()
{
    cout << "Deck:\t\t";
    string blackSquare = "\u25A0";
    for (int i = 1; i <= MAXCARDSINDECK - placeinDeck; i++)
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
    Card * temp = &deckTobeshuffled[placeinDeck];
    placeinDeck++;
    return temp;

    // return &(deckForGame[placeinDeck++])
}
