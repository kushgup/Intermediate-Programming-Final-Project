#ifndef __pg7b__Deck__
#define __pg7b__Deck__

#include <stdio.h>
#include "Card.h"

#define MAXCARDSINDECK 55

class Deck
{
    Card deckTobeshuffled[52];
    Card startCamels[3];
    Card deckForGame[MAXCARDSINDECK];
    int placeinDeck;

public:

    Deck();
    //~Deck();

    void printDeck();
    void shuffle();
    void restoreDeck(){placeinDeck = 0;};
    void increasePlaceinDeck(){placeinDeck++;};
    Card * dealCard();
    int getPlaceInDeck() const { return placeinDeck; };

private:

    void swap (int, int);

};

#endif /* defined(__pg7b__Deck__) */
