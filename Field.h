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

    vector<Card*> market;
    vector<Card*> goodsToBeTaken;
    vector<Card*> goodsToBeGiven;
    Deck deck;
    stack<Card*> discardPile;
    vector<Card*> player1Hand;
    vector<Card*> player2Hand;



public:
    Field();
    void printField();
    vector<Card*> getP1Hand(){return player1Hand;};
    vector<Card*> getP2Hand(){return player2Hand;};
    Deck * getDeck() {return &deck;};
    void restoreDeck(){deck.Deck::restoreDeck();};

    //void moveGoodFromMarket();
    //void cleanGoodsToBeTaken();
    //The the field can do right now is be printed it will eventually be able to work with move for game play
};

#endif /* defined(__pg7b__Field__) */
