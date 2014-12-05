//
//  Deck.h
//  pg7b
//
//  Created by Edmund Connor on 11/23/14.
//  Copyright (c) 2014 Edmund Connor. All rights reserved.
//

#ifndef __pg7b__Deck__
#define __pg7b__Deck__

#include <stdio.h>
#include "Card.h"
#define MAXCARDSINDECK 55
using namespace std;

class Deck
{
    Card deckTobeshuffled [52];
    Card startCamels[3];
    Card deckForGame [MAXCARDSINDECK];
    int placeinDeck;
    
public:
    Deck();
    void printDeck();
    void shuffle();
    void restoreDeck(){placeinDeck = 0;};
    void increasePlaceinDeck(){placeinDeck++;};
    Card * dealCard();
    
private:
    void swap (int, int);
    
};

#endif /* defined(__pg7b__Deck__) */
