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
    cout << "swapping: " << a << "-->" << b << endl;
    //Card temp ( deckTobeshuffled[a] );
    Card temp;
    temp.identifier = deckTobeshuffled[a].identifier;
    temp.isCamel = deckTobeshuffled[a].isCamel;
    temp.PandaCamel = deckTobeshuffled[a].PandaCamel;
    temp.isPrecious = deckTobeshuffled[a].isPrecious;
    temp.rank = deckTobeshuffled[a].rank;

    //deckTobeshuffled[a] = deckTobeshuffled[b];
    deckTobeshuffled[a].identifier = deckTobeshuffled[b].identifier;
    deckTobeshuffled[a].isCamel = deckTobeshuffled[b].isCamel;
    deckTobeshuffled[a].PandaCamel = deckTobeshuffled[b].PandaCamel;
    deckTobeshuffled[a].isPrecious = deckTobeshuffled[b].isPrecious;
    deckTobeshuffled[a].rank = deckTobeshuffled[b].rank;

    //deckTobeshuffled[b] = temp;
    deckTobeshuffled[b].identifier = temp.identifier;
    deckTobeshuffled[b].isCamel = temp.isCamel;
    deckTobeshuffled[b].PandaCamel = temp.PandaCamel;
    deckTobeshuffled[b].isPrecious = temp.isPrecious;
    deckTobeshuffled[b].rank = temp.rank;
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
