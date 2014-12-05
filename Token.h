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
    Token(): value(0), TypeOfToken("NoType") {};
    Token(string str): TypeOfToken(str) {};
    Token(int v, string str): value(v), TypeOfToken(str) {};
    //~Token();
    void setValue(int);
    void setType(string);
    int getValue() const;
    string getType() const;
    void printToken() const;

};

#endif /* defined(__pg7b__Token__) */
