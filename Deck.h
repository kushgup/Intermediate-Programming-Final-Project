#ifndef __pg7b__Deck__
#define __pg7b__Deck__

#include "Card.h"
#include <cstdio>

#define MAXCARDSINDECK 55

class Deck
{
private:
    friend class Game;

    Card deckTobeshuffled[MAXCARDSINDECK]; // this seems to call Card() default constructor on all array elements automatically
    int placeinDeck;

public:

    Deck();
    //~Deck();

    void printDeck() const;
    void shuffle();
    void increasePlaceinDeck(){placeinDeck++;};
    Card * dealCard();
    int getPlaceInDeck() const { return placeinDeck; };

private:
    void swap (int, int);

};

#endif /* defined(__pg7b__Deck__) */
