#include "Card.h"
#include <stdio.h>
#include <iostream>
using namespace std;

Card::Card()
{
    isCamel = false;
    isPrecious = false;
    PandaCamel = false;
    identifier = "NA";
}

Card::Card(string Id)
{
    identifier = Id;
    PandaCamel = false;

    if(Id == "Camel")
        isCamel = true;
    else
        isCamel = false;

    if(Id == "Gold" || Id == "Silver" || Id == "Diamonds")
        isPrecious = true;
    else
        isPrecious = false;
}

Card::Card(Card & other)
{
    identifier = other.identifier;
    isCamel = other.isCamel;
    PandaCamel = other.PandaCamel;
}

/*Card::~Card()
{
    delete this;
}
*/
string Card::getIdentifier() const
{
    return this->identifier;
}

bool Card::getIsCamel() const
{
    return isCamel;
}

bool Card::getIsPandaCamel() const
{
    return PandaCamel;
}

void Card::setPandaCamel()
{
    this->PandaCamel = true;
}

void Card::printCard() const
{
    cout << this->identifier;
}

bool Card::operator== (Card & other)
{
    return this->identifier == other.getIdentifier();
}














