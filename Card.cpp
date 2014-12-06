#include "Card.h"
#include <stdio.h>
#include <iostream>
using namespace std;

Card::Card(string Id): identifier(Id), isCamel(false), PandaCamel(false), isPrecious(false), rank(0)
{
    if(Id == "Camel")
        isCamel = true;

    if(Id == "Gold" || Id == "Silver" || Id == "Diamonds")
        isPrecious = true;

    if(Id == "Diamonds")
        rank = 6;
    else if(Id == "Gold")
        rank = 5;
    else if(Id == "Silver")
        rank = 4;
    else if(Id == "Cloth")
        rank = 3;
    else if(Id == "Spice")
        rank = 2;
    else if(Id == "Paper")
        rank = 1;

}

Card::Card(Card & other)
{
    identifier = other.identifier;
    isCamel = other.isCamel;
    PandaCamel = other.PandaCamel;
    isPrecious = other.isPrecious;
    rank = other.rank;
}
/*
Card::~Card()
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

bool Card::operator== (const Card & other)
{
    return this->rank == other.getRank();
}

bool Card::operator > (const Card & other)
{
    return this->getRank() > other.getRank();
}

bool Card::operator >= (const Card & other)
{
    return this->getRank() >= other.getRank();
}

bool Card::operator <= (const Card & other)
{
    return this->getRank() <= other.getRank();
}

bool Card::operator < (const Card & other)
{
    return this->getRank() < other.getRank();
}

bool Card::operator != (const Card & other)
{
    return this->getRank() != other.getRank();
}
