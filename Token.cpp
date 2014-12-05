//
//  Token.cpp
//  pg7b
//
//  Created by Edmund Connor on 11/23/14.
//  Copyright (c) 2014 Edmund Connor. All rights reserved.
//

#include "Token.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Token::Token()
{
    value = 0;
    TypeOfToken = "NoType";
}

Token::Token(int v, string k)
{
    value = v;
    TypeOfToken = k;
}

void Token::setType(string y)
{
    TypeOfToken = y;
}

void Token::setValue(int x)
{
    value = x;
}

int Token::getValue() const
{
    return value;
}

string Token::getType() const
{
    return TypeOfToken;
}

void Token::printToken() const
{
    cout << TypeOfToken << ":" << value;
}



