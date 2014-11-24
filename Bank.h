//
//  Bank.h
//  pg7b
//
//  Created by Edmund Connor on 11/19/14.
//  Copyright (c) 2014 Edmund Connor. All rights reserved.
//

#ifndef __pg7b__Bank__
#define __pg7b__Bank__

#include <stdio.h>
#include "Token.h"
using namespace std;

class Bank
{
    Token bank [6][9];
    Token bonuses [3][7];
    Token seals [3];
    Token camelToken;
    
    /*  Bank Token Order
     *  Paper   (0)
     *  Spice   (1)
     *  Cloth   (2)
     *  Silver  (3)
     *  Gold    (4)
     *  Diamonds(5)
     */
    
public:
    Bank();
    Bank(Bank &);
    //~Bank();
    Token takeFromBank(int); //Pop Top
    Token takeBonus(int); //Pop Top
    Token takeSeal();
    Token getCamelToken();
    
    void printBank();
    
};

#endif /* defined(__pg7b__Bank__) */
