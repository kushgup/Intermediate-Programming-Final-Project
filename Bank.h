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
#include <array>
#include <vector>
#include <map>
#define NUMPAPER 9
#define NUMSPICE 7
#define NUMCLOTH 7
#define NUMSILVER 5
#define NUMGOLD 5
#define NUMDIAMONDS 5
#define NUM3S 7
#define NUM4S 6
#define NUM5S 5
using namespace std;

class Bank
{
    std::array<std::vector<Token>, 6> goodsTs{{std::vector<Token>(NUMPAPER), std::vector<Token>(NUMSPICE), std::vector<Token>(NUMCLOTH), std::vector<Token>(NUMSILVER), std::vector<Token>(NUMGOLD), std::vector<Token>(NUMDIAMONDS)}};
    
    std::array<std::vector<Token>, 3> bonuses{{std::vector<Token>(NUM3S), std::vector<Token>(NUM4S), std::vector<Token>(NUM5S)}};
    
    Token seals [3];
    int numofSealsLeft;
    Token camelToken;
    
    map <string, int> MaxTokensForGoodsTs;
    map <int, int> MaxTokensForBonuses;
    
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
    Token * takeTokenFromGoodTs(string); //Pop Top
    Token * takeBonus(int); //Pop Top
    Token * takeSeal();
    Token * getCamelToken();
    void printBank();
    void refillBank();
    
private:
    void shuffleBonus();
    void swap3(int, int);
    void swap4(int, int);
    void swap5(int, int);
    
};

#endif /* defined(__pg7b__Bank__) */
