//
//  Field.h
//  pg7b
//
//  Created by Edmund Connor on 11/25/14.
//  Copyright (c) 2014 Edmund Connor. All rights reserved.
//

#ifndef __pg7b__Field__
#define __pg7b__Field__

#include <stdio.h>
#include <vector>
#include <stack>
#include "Deck.h"
#include "Card.h"


using namespace std;


class Field {

    friend class Move; // needed so that Move can access Game's field
    friend class Player; // needed so that Player can look into Game's field to move stuff

    Deck deck; // by default, deck constructor is called here

    vector<Card*> market;



public:
    Field();
    void printField();
    Deck * getDeck() {return &deck;};
    void restoreDeck(){deck.Deck::restoreDeck();};

    //void moveGoodFromMarket();
    //void cleanGoodsToBeTaken();
    //The the field can do right now is be printed it will eventually be able to work with move for game play
};

#endif /* defined(__pg7b__Field__) */
