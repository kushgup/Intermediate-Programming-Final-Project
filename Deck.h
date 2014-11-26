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
using namespace std;

class Deck
{
    Card deckTobeshuffled [52];
    Card startCamels[3];
    Card deckForGame [55];
    int placeinDeck;
    
public:
    Deck();
    //Deck(Deck &);
    //~Deck();
    Card getCardatIndex(int);
    void printDeck();
    void shuffle();
    //void dealRound; //not sure how this will work in the overall game
    void restoreDeck(){placeinDeck = 0;};
    void increasePlaceinDeck(){placeinDeck++;};
    Card * dealCard();
    
private:
    void swap (int, int);
    
};

#endif /* defined(__pg7b__Deck__) */
