#ifndef __pg7__Field__
#define __pg7__Field__

#include "Deck.h"
#include "Card.h"
#include <stdio.h>
#include <vector>
#include <stack>

using std::vector;

class Field {

private:

    friend class Move; // needed so that Move can access Game's field
    friend class Player; // needed so that Player can look into Game's field to move stuff
    friend class Game; // allows Game to access Deck for dealing initial hand to players

    Deck deck; // by default, deck constructor is called here
    vector<Card*> market;

public:

    Field();

    void printField() const;
    Deck * getDeck() { return &deck; };
    void refillMarket() { while(market.size() < 5) market.push_back(deck.dealCard()); };
    void restoreDeck() { deck.restoreDeck(); };

};

#endif /* defined(__pg7b__Field__) */
