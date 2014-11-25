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


using std::string;

class Card
{
    string identifier;
    bool isCamel;
    bool PandaCamel;
    bool isPrecious;

public:
    Card();
    Card(string);
    Card(Card &);
    ~Card();
    string getIdentifier() const;
    bool getIsCamel() const;
    void setPandaCamel();
    bool getIsPandaCamel() const;
    void printCard() const;
};

#endif /* defined(__pg7b__Card__) */
