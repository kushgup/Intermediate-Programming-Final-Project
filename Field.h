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

using namespace std;


class Field
{
    vector<Card*> market;
    vector<Card*> goodsToBeTaken;
    vector<Card*> goodsToBeGiven;
    Deck deck;
    
public:
    Field();
    void printField();
    //void moveGoodFromMarket();
    //void cleanGoodsToBeTaken();
    //The the field can do right now is be printed it will eventually be able to work with move for game play
    
    //need a function to take a card from the deck into the market

};

#endif /* defined(__pg7b__Field__) */
