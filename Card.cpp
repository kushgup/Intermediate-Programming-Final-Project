#include "Card.h"
#include <stdio.h>
#include <iostream>

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
