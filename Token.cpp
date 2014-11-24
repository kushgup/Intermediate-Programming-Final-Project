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

Token::Token(int v, string k)
{
    value = v;
    TypeOfToken = k;
}

Token::Token(Token & other)
{
    value = other.getValue();
    TypeOfToken = other.getType();
}

Token::~Token()
{
    delete this;
}

void Token::setValue(int x)
{
    this->value = x;
}

int Token::getValue() const
{
    return this->value;
}

string Token::getType() const
{
    return this->TypeOfToken;
}

void Token::printToken() const
{
    cout << TypeOfToken << ":" << value;
}

