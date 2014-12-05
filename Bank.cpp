#include "Bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Token.h"
#include <array>
using namespace std;
#define NUMPAPER 9
#define NUMSPICE 7
#define NUMCLOTH 7
#define NUMSILVER 5
#define NUMGOLD 5
#define NUMDIAMONDS 5
#define NUM3S 7
#define NUM4S 6
#define NUM5S 5
#define NUMSEALS 3

Bank::Bank()
{

    for (int i = 0; i < NUMPAPER; i++)
    {
        goodsTs[0][i] = *new Token ();
        goodsTs[0][i].Token::setType("Paper");
        goodsTs[0][i].Token::setValue(1);
        if(i == 8)
            goodsTs[0][i].Token::setValue(4);
        if(i == 7)
            goodsTs[0][i].Token::setValue(3);
        if(i == 6)
            goodsTs[0][i].Token::setValue(2);

    }

    for (int i = 0; i < NUMSPICE; i++)
    {
        goodsTs[1][i] = *new Token ();
        goodsTs[1][i].Token::setType("Spice");
        if(i == 6)
            goodsTs[1][6].Token::setValue(5);
        else if(i == 5 || i == 4)
            goodsTs[1][i].Token::setValue(3);
        else if(i == 3 || i == 2)
            goodsTs[1][i].Token::setValue(2);
        else
            goodsTs[1][i].setValue(1);
    }

    for (int i = 0; i < NUMCLOTH; i++)
    {
        goodsTs[2][i] = *new Token ();
        goodsTs[2][i].Token::setType("Cloth");
        if(i == 6)
            goodsTs[2][6].Token::setValue(5);
        else if(i == 5 || i == 4)
            goodsTs[2][i].Token::setValue(3);
        else if(i == 3 || i == 2)
            goodsTs[2][i].setValue(2);
        else
            goodsTs[2][i].Token::setValue(1);
    }

    for (int i = 0; i < NUMSILVER; i++)
    {
        goodsTs[3][i] = *new Token ();
        goodsTs[3][i].Token::setValue(5);
        goodsTs[3][i].Token::setType("Silver");
    }

    for (int i = 0; i < NUMGOLD; i++)
    {
        goodsTs[4][i] = *new Token ();
        goodsTs[4][i].Token::setType("Gold");
        if(i <= 2)
            goodsTs[4][i].Token::setValue(5);
        else
            goodsTs[4][i].Token::setValue(6);
    }

    for (int i = 0; i < NUMDIAMONDS; i++)
    {
        goodsTs[5][i] = *new Token ();
        goodsTs[5][i].Token::setType("Diamonds");
        if(i <= 2)
            goodsTs[5][i].Token::setValue(5);
        else
            goodsTs[5][i].Token::setValue(7);
    }

    for (int i = 0; i < NUM3S; i++)
    {
        bonuses[0][i] = *new Token ();
        bonuses[0][i].Token::setType("Bonus3");
        if (i < 2)
            bonuses[0][i].Token::setValue(1);
        else if (i > 4)
            bonuses[0][i].Token::setValue(3);
        else
            bonuses[0][i].Token::setValue(2);
    }

    for (int i = 0; i < NUM4S; i++)
    {
        bonuses[1][i] = *new Token ();
        bonuses[1][i].Token::setType("Bonus4");
        if (i < 2)
            bonuses[1][i].Token::setValue(4);
        else if (i > 3)
            bonuses[1][i].Token::setValue(6);
        else
            bonuses[1][i].Token::setValue(5);
    }

    for (int i = 0; i < NUM5S; i++)
    {
        bonuses[2][i] = *new Token ();
        bonuses[2][i].Token::setType("Bonus5");
        if (i < 2)
            bonuses[2][i].Token::setValue(8);
        else if (i > 2)
            bonuses[2][i].Token::setValue(10);
        else
            bonuses[2][i].Token::setValue(9);
    }

    for (int i = 0; i < 3; i++)
    {
        seals[i] = *new Token();
        seals[i].Token::setType("Seal");
        seals[i].Token::setValue(100);
    }
    numofSealsLeft = NUMSEALS;

    camelToken = *new Token ();
    camelToken.Token::setType("Camel");
    camelToken.Token::setValue(5);

    MaxTokensForGoodsTs["Paper"] = NUMPAPER;
    MaxTokensForGoodsTs["Spice"] = NUMSPICE;
    MaxTokensForGoodsTs["Cloth"] = NUMCLOTH;
    MaxTokensForGoodsTs["Silver"] = NUMSILVER;
    MaxTokensForGoodsTs["Gold"] = NUMGOLD;
    MaxTokensForGoodsTs["Diamonds"] = NUMDIAMONDS;

    MaxTokensForBonuses[3] = NUM3S;
    MaxTokensForBonuses[4] = NUM4S;
    MaxTokensForBonuses[5] = NUM5S;

    this->shuffleBonus();
}

Bank::Bank(Bank & other)
{
    for(int i = 0; i< 6; i++)
    {
        for(int j = 0; j < (int) goodsTs[i].size(); j++)
        {
            goodsTs[i][j] = other.goodsTs[i][j];
        }
    }
    for(int i = 0; i< 3; i++)
    {
        for(int j = 0; j < (int) bonuses[i].size(); j++)
        {
            bonuses[i][j] = other.bonuses[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        seals[i] = other.seals[i];
    }
    numofSealsLeft = NUMSEALS;

    camelToken = other.camelToken;

    MaxTokensForGoodsTs["Paper"] = NUMPAPER;
    MaxTokensForGoodsTs["Spice"] = NUMSPICE;
    MaxTokensForGoodsTs["Cloth"] = NUMCLOTH;
    MaxTokensForGoodsTs["Silver"] = NUMSILVER;
    MaxTokensForGoodsTs["Gold"] = NUMGOLD;
    MaxTokensForGoodsTs["Diamonds"] = NUMDIAMONDS;

    MaxTokensForBonuses[3] = NUM3S;
    MaxTokensForBonuses[4] = NUM4S;
    MaxTokensForBonuses[5] = NUM5S;
}

/*
Bank::~Bank()
{
    delete [] bank;
    delete [] bonuses;
    delete [] seals;
    delete camelToken;
}
*/

Token * Bank::takeTokenFromGoodTs(string goodYourTaking) //Pop Top
{
    //error catching
    int kindofGoodYourTaking = 0; //inital is paper
    if(goodYourTaking == "Spice")
        kindofGoodYourTaking = 1;
    if(goodYourTaking == "Cloth")
        kindofGoodYourTaking = 2;
    if(goodYourTaking == "Silver")
        kindofGoodYourTaking = 3;
    if(goodYourTaking == "Gold")
        kindofGoodYourTaking = 4;
    if(goodYourTaking == "Diamonds")
        kindofGoodYourTaking = 5;

    int placeTakingFrom = MaxTokensForGoodsTs[goodYourTaking]-1;
    MaxTokensForGoodsTs[goodYourTaking]--;

    return &goodsTs[kindofGoodYourTaking][placeTakingFrom];
}

Token * Bank::takeBonusToken(int BonusTaking) //Pop Top
{
    int placeTakingFrom = MaxTokensForBonuses[BonusTaking];
    Token * temp = &bonuses[BonusTaking-3][placeTakingFrom];
    MaxTokensForBonuses[BonusTaking]--;
    return temp;
}

Token * Bank::takeSeal()
{
    numofSealsLeft--;
    return &(seals[1]);
}

Token * Bank::getCamelToken()
{
    Token * temp = &camelToken;
    return temp;
}

void Bank::printBank()
{
    cout << "Bank **********************************************" << endl;
    for(int i=0; i< 6 ;i++)
    {
        string mapiter = "Paper";
        if(i == 1)
            mapiter = "Spice";
        if(i == 2)
            mapiter = "Cloth";
        if(i == 3)
            mapiter = "Silver";
        if(i == 4)
            mapiter = "Gold";
        if(i == 5)
            mapiter = "Diamonds";

        int num_elements = MaxTokensForGoodsTs[mapiter];

        if(goodsTs[i][0].getType() == "Diamonds")
            cout << goodsTs[i][0].getType() << " Tokens: \t";
        else
            cout << goodsTs[i][0].getType() << " Tokens: \t\t";
        for (int k = 0; k< num_elements; k++)
        {
            int toBePrinted = goodsTs[i][k].getValue();
            if(toBePrinted)
                cout << toBePrinted << " ";
        }
        cout << endl;
    }

    for(int i=0; i< 3 ;i++)
    {
        int num_elements = MaxTokensForBonuses[i+3];
        cout << bonuses[i][0].getType() << " Tokens: \t\t";
        //char blackCircle = '\u25CF';
        for (int k = 0; k< num_elements; k++)
        {
            int toBePrinted = bonuses[i][k].getValue();
            if(toBePrinted)
                cout << "o ";
        }
        cout << endl;
    }
    cout << "Seals: \t\t\t";
    for(int i = 0; i< numofSealsLeft; i++)
    {
        int toBePrinted = seals[i].getValue();
        if(toBePrinted)
            cout << "o ";
    }
    cout << endl;
    cout << "Camel Token: \t\t5"<<endl;
    cout << endl;
}

void Bank::shuffleBonus()
{
    //srand(time(NULL));

    for (int i = 0; i < 7; i++)
    {
        int b3 = rand() % 7;
        swap3(i, b3);
    }
    for (int i = 0; i < 6; i++)
    {
        int b4 = rand() % 6;
        swap4(i, b4);
    }
    for (int i = 0; i < 5; i++)
    {
        int b5 = rand() % 5;
        swap5(i, b5);
    }

}

void Bank::swap3 (int a, int b)
{
    Token temp = bonuses[0][a];
    bonuses[0][a]=bonuses[0][b];
    bonuses[0][b] = temp;

}

void Bank::swap4 (int a, int b)
{
    Token temp = bonuses[1][a];
    bonuses[1][a]=bonuses[1][b];
    bonuses[1][b] = temp;

}

void Bank::swap5 (int a, int b)
{
    Token temp = bonuses[2][a];
    bonuses[2][a]=bonuses[2][b];
    bonuses[2][b] = temp;

}

void Bank::refillBank()
{
    MaxTokensForGoodsTs["Paper"] = NUMPAPER;
    MaxTokensForGoodsTs["Spice"] = NUMSPICE;
    MaxTokensForGoodsTs["Cloth"] = NUMCLOTH;
    MaxTokensForGoodsTs["Silver"] = NUMSILVER;
    MaxTokensForGoodsTs["Gold"] = NUMGOLD;
    MaxTokensForGoodsTs["Diamonds"] = NUMDIAMONDS;

    MaxTokensForBonuses[3] = NUM3S;
    MaxTokensForBonuses[4] = NUM4S;
    MaxTokensForBonuses[5] = NUM5S;

    numofSealsLeft = NUMSEALS;
}

bool Bank::isGoodDepleted(string good)
{
    return (MaxTokensForGoodsTs[good] == 0);
}

bool Bank::isBonusDepleted(int bonus)
{
    return (MaxTokensForBonuses[bonus] == 0);
}

int Bank::isDepleted()
{
    int depletedTokens = 0;
    if( MaxTokensForGoodsTs["Paper"] == 0) {
        depletedTokens++;
    }
    if(MaxTokensForGoodsTs["Spice"] == 0) {
        depletedTokens++;
    }
    if(MaxTokensForGoodsTs["Cloth"] == 0) {
        depletedTokens++;
    }
    if(MaxTokensForGoodsTs["Silver"] == 0) {
        depletedTokens++;
    }
    if(MaxTokensForGoodsTs["Gold"] == 0) {
        depletedTokens++;
    }
    if(MaxTokensForGoodsTs["Diamonds"] == 0) {
        depletedTokens++;
    }

    return depletedTokens;
}
