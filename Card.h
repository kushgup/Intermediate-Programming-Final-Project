#ifndef __pg7__Card__
#define __pg7__Card__

#include <stdio.h>
#include <iostream>

using std::string;

class Card
{
private:

    string identifier;
    bool isCamel;
    bool PandaCamel;
    bool isPrecious;
    int rank;

public:
    Card(): identifier("NA"), isCamel(false), PandaCamel(false), isPrecious(false), rank(0) {};
    Card(string id);
    Card(Card & other): identifier(other.identifier), isCamel(other.isCamel), PandaCamel(other.PandaCamel), isPrecious(other.isPrecious), rank(other.rank) { };

    string getIdentifier() const { return identifier; };
    bool getIsCamel() const { return isCamel; };
    int getRank() const { return rank;};
    void setPandaCamel() { PandaCamel = true; };
    bool getPrecious() const { return isPrecious;};
    bool getIsPandaCamel() const { return PandaCamel; };
    void printCard() const { cout << this->identifier; };
    
    bool operator< (const Card & other) const { return this->getRank() < other.getRank(); };
    bool operator> (const Card & other) const { return this->getRank() > other.getRank(); };
    bool operator== (const Card & other) const { return this->getRank() == other.getRank(); };
    bool operator!= (const Card & other) const { return this->getRank() != other.getRank(); };
    bool operator>= (const Card & other) const { return this->getRank() >= other.getRank(); };
    bool operator<= (const Card & other) const { return this->getRank() >= other.getRank(); };

};

#endif /* defined(__pg7b__Card__) */
