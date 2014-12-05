#ifndef __pg7b__Token__
#define __pg7b__Token__

#include <stdio.h>
#include <iostream>

using namespace std;

class Token
{

    int value;
    string TypeOfToken;

public:
    Token();
    Token(int, string);
    Token(Token &);
    //~Token();
    void setValue(int);
    void setType(string);
    int getValue() const;
    string getType() const;
    void printToken() const;

};

#endif /* defined(__pg7b__Token__) */
