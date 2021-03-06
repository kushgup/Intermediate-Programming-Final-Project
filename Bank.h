#ifndef __pg7b__Bank__
#define __pg7b__Bank__

#define NUMPAPER 9
#define NUMSPICE 7
#define NUMCLOTH 7
#define NUMSILVER 5
#define NUMGOLD 5
#define NUMDIAMONDS 5
#define NUM3S 7
#define NUM4S 6
#define NUM5S 5

#include "Token.h"
#include <array>
#include <vector>
#include <map>
#include <iostream>

using std::array;
using std::vector;
using std::string;

class Bank
{
    array <vector<Token>, 6> goodsTs;
    array <vector<Token>, 3> bonuses;
    string types[6];

    Token seals[3];
    int numofSealsLeft;
    Token camelToken;

    map <string, int> MaxTokensForGoodsTs; // associative array, keeps track of which tokens can be issued
    map <int, int> MaxTokensForBonuses; // associative array, keeps track of which tokens can be issued

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
    Token * takeBonusToken(int); //Pop Top
    Token * takeSeal();
    Token * getCamelToken();
    void printBank();
    void refillBank();
    bool isGoodDepleted(string good) { return MaxTokensForGoodsTs[good] == 0; };
    bool isBonusDepleted(int bonus) { return MaxTokensForBonuses[bonus] == 0; };
    int isDepleted();
    Token * temp0; //for when there arent enough tokens to be returned as are being sold.

private:
    void shuffleBonus();
    void swap(int, int, int);

};

#endif /* defined(__pg7b__Bank__) */
