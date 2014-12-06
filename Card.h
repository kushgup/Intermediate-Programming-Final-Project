
#ifndef __pg7b__Card__
#define __pg7b__Card__

#include <stdio.h>
#include <iostream>
using namespace std;

class Card
{
    friend class Deck; // TAKE THIS OUT. FOR TESTING ONLY

    string identifier;
    bool isCamel;
    bool PandaCamel;
    bool isPrecious;
    int rank;

public:
    Card(): identifier("NA"), isCamel(false), PandaCamel(false), isPrecious(false), rank(0) {};
    Card(string id);
    Card(Card &);
    //~Card();
    string getIdentifier() const;
    void setIdentifier(string);
    bool getIsCamel() const;
    int getRank() const {return rank;};
    void setPandaCamel();
    bool getPrecious(){return isPrecious;};
    bool getIsPandaCamel() const;
    void printCard() const;
    bool operator== (const Card&);
    bool operator> (const Card&);
    bool operator>= (const Card&);
    bool operator< (const Card&);
    bool operator<= (const Card&);
    bool operator!= (const Card&);
    bool operator= (const Card &);

};

#endif /* defined(__pg7b__Card__) */
