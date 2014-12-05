//
//  Card.h
//  pg7b
//
//  Created by Edmund Connor on 11/23/14.
//  Copyright (c) 2014 Edmund Connor. All rights reserved.
//

#ifndef __pg7b__Card__
#define __pg7b__Card__

#include <stdio.h>
#include <iostream>
using namespace std;

class Card
{
    string identifier;
    bool isCamel;
    bool PandaCamel;
    bool isPrecious;
    int rank;
    
public:
    Card();
    Card(string);
    Card(Card &);
    //~Card();
    string getIdentifier() const;
    void setIdentifier(string);
    bool getIsCamel() const;
    int getRank() const;
    void setPandaCamel();
    bool getIsPandaCamel() const;
    void printCard() const;
    bool operator== (Card&);
    bool operator> (Card&);
    bool operator>= (Card&);
    bool operator< (Card&);
    bool operator<= (Card&);
    bool operator!= (Card&);

};

#endif /* defined(__pg7b__Card__) */
