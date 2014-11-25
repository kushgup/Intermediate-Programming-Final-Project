//
//  Token.h
//  pg7b
//
//  Created by Edmund Connor on 11/23/14.
//  Copyright (c) 2014 Edmund Connor. All rights reserved.
//

#ifndef __pg7b__Token__
#define __pg7b__Token__

#include <stdio.h>
#include <iostream>

using std::string;

class Token
{
    int value;
    string TypeOfToken;

public:
    Token(int, string);
    Token(Token &);
    ~Token();
    void setValue(int);
    int getValue() const;
    string getType() const;
    void printToken() const;

};

#endif /* defined(__pg7b__Token__) */
