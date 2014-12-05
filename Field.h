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
#include "Deck.h"
#include "Card.h"
#include <vector>
#include <stack>

using namespace std;


class Field {

    friend class Move;
    friend class Player;

    vector<Card*> market;
    vector<Card*> goodsToBeTaken;
    vector<Card*> goodsToBeGiven;
    Deck deck = *new Deck();
    stack<Card*> discardPile;
    vector<Card*> player1Hand;
    vector<Card*> player2Hand;



public:
    Field();
    void printField();
    vector<Card*> getP1Hand(){return player1Hand;};
    vector<Card*> getP2Hand(){return player2Hand;};

    //void moveGoodFromMarket();
    //void cleanGoodsToBeTaken();
    //The the field can do right now is be printed it will eventually be able to work with move for game play
};

#endif /* defined(__pg7b__Field__) */
