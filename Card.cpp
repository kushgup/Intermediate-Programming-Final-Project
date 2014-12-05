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
    rank = 0;
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
    
    rank = 0;
    if(Id == "Diamonds")
        rank = 6;
    if(Id == "Gold")
        rank = 5;
    if(Id == "Silver")
        rank = 4;
    if(Id == "Cloth")
        rank = 3;
    if(Id == "Spice")
        rank = 2;
    if(Id == "Paper")
        rank = 1;
    
}

Card::Card(Card & other)
{
    identifier = other.identifier;
    isCamel = other.isCamel;
    PandaCamel = other.PandaCamel;
    rank = 0;
    if(identifier == "Diamonds")
        rank = 6;
    if(identifier == "Gold")
        rank = 5;
    if(identifier == "Silver")
        rank = 4;
    if(identifier == "Cloth")
        rank = 3;
    if(identifier == "Spice")
        rank = 2;
    if(identifier == "Paper")
        rank = 1;
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













