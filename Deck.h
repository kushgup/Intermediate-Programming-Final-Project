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
    Card deck [52];
    Card startCamels[3];
    
public:
    Deck();
    Deck(Deck &);
    ~Deck();
    Card getCardatIndex(int);
    void printDeck();
    void shuffle();
    void swap (int *, int *);
    
};

#endif /* defined(__pg7b__Deck__) */
