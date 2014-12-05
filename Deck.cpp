#include "Deck.h"
#include <array>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using std::string;

Deck::Deck()
{
    int i;
    for(i = 0; i < 11; i++)
    {
        deckTobeshuffled[i] = Card("Camel");
    }
    for(; i < 21; i++)
    {
        deckTobeshuffled[i] = Card("Paper");
    }
    for(; i < 29; i++)
    {
        deckTobeshuffled[i] = Card("Spice");
    }
    for(; i < 37; i++)
    {
        deckTobeshuffled[i] = Card("Cloth");
    }
    for(; i < 43; i++)
    {
        deckTobeshuffled[i] = Card("Silver");
    }
    for(; i < 49; i++)
    {
        deckTobeshuffled[i] = Card("Gold");
    }
    for(; i <= 52; i++)
    {
        deckTobeshuffled[i] = Card("Diamonds");
    }
    shuffle();
    for(; i < 55; i++)
    {
        deckTobeshuffled[i] = Card("Camel");
        if(i == 53)
            deckTobeshuffled[i].setPandaCamel();
        swap(i, i - 52);
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

    //shuffle the deck by iterating 60 times, have a random number generator, swap cards in the deck
    int x, i;
    Card temp;
    srand(time(NULL));
    for (i = 0; i < num_cards; i++) {
        x = rand() / (RAND_MAX / num_cards + 1);
        swap(i, x);
        // temp = (game->deck)[i];
        // (game->deck)[i] = (game->deck)[x];
        // (game->deck)[x] = temp;
    }

    // int seed;
    // time_t t;
    // seed = (int) time(&t);
    // srand((unsigned) seed);
    // for(int i = 0; i< 52; i++)
    // {
    //     int s = rand() % 52;
    //     swap(i, s);
    // }
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
    Card * temp = &deckForGame[placeinDeck];
    placeinDeck++;
    return temp;

    // return &(deckForGame[placeinDeck++])
}
