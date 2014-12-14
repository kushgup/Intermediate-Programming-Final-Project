#ifndef __pg7b__Token__
#define __pg7b__Token__

#include <stdio.h>
#include <iostream>

using namespace std;

class Token
{
private:
    int value;
    string type;

public:
    Token(): value(0), type("NoType") { };
    Token(string str): type(str) { };
    Token(int v, string str): value(v), type(str) { };
    //~Token();
    void setValue(int x) { value = x; };
    void setType(string y) { type = y; };
    int getValue() const { return value; };
    string getType() const { return type; };
    void printToken() const { cout << type << ":" << value; };

};

#endif /* defined(__pg7b__Token__) */
