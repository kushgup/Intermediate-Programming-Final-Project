#include "Bank.h"
#include <stdlib.h>
#include <time.h>
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
    goodsTs =
    {{
        vector<Token>(NUMPAPER),
        vector<Token>(NUMSPICE),
        vector<Token>(NUMCLOTH),
        vector<Token>(NUMSILVER),
        vector<Token>(NUMGOLD),
        vector<Token>(NUMDIAMONDS)
    }};

    bonuses =
    {{
        vector<Token>(NUM3S),
        vector<Token>(NUM4S),
        vector<Token>(NUM5S)
    }};

    types[0] = "Paper", types[1]= "Spice", types[2] = "Cloth", types[3] = "Silver", types[4] = "Gold", types[5] = "Diamonds";

    int i;
    for (i = 0; i < NUMPAPER; i++)
    {
        goodsTs[0][i] = Token (1, "Paper");
        if(i == 8)
            goodsTs[0][i].setValue(4);
        if(i == 7)
            goodsTs[0][i].setValue(3);
        if(i == 6)
            goodsTs[0][i].setValue(2);

    }

    for (i = 0; i < NUMSPICE; i++)
    {
        goodsTs[1][i] = Token ("Spice");
        if(i == 6)
            goodsTs[1][6].setValue(5);
        else if(i == 5 || i == 4)
            goodsTs[1][i].setValue(3);
        else if(i == 3 || i == 2)
            goodsTs[1][i].setValue(2);
        else
            goodsTs[1][i].setValue(1);
    }

    for (i = 0; i < NUMCLOTH; i++)
    {
        goodsTs[2][i] = Token ("Cloth");
        if(i == 6)
            goodsTs[2][6].setValue(5);
        else if(i == 5 || i == 4)
            goodsTs[2][i].setValue(3);
        else if(i == 3 || i == 2)
            goodsTs[2][i].setValue(2);
        else
            goodsTs[2][i].setValue(1);
    }

    for (i = 0; i < NUMSILVER; i++)
    {
        goodsTs[3][i] = Token (5, "Silver");

    }

    for (i = 0; i < NUMGOLD; i++)
    {
        goodsTs[4][i] = Token ("Gold");
        if(i <= 2)
            goodsTs[4][i].setValue(5);
        else
            goodsTs[4][i].setValue(6);
    }

    for (i = 0; i < NUMDIAMONDS; i++)
    {
        goodsTs[5][i] = Token ("Diamonds");
        if(i <= 2)
            goodsTs[5][i].setValue(5);
        else
            goodsTs[5][i].setValue(7);
    }

    for (i = 0; i < NUM3S; i++)
    {
        bonuses[0][i] = Token ("Bonus3");
        if (i < 2)
            bonuses[0][i].setValue(1);
        else if (i > 4)
            bonuses[0][i].setValue(3);
        else
            bonuses[0][i].setValue(2);
    }

    for (i = 0; i < NUM4S; i++)
    {
        bonuses[1][i] = Token ("Bonus4");
        if (i < 2)
            bonuses[1][i].setValue(4);
        else if (i > 3)
            bonuses[1][i].setValue(6);
        else
            bonuses[1][i].setValue(5);
    }

    for (i = 0; i < NUM5S; i++)
    {
        bonuses[2][i] = Token ("Bonus5");
        if (i < 2)
            bonuses[2][i].setValue(8);
        else if (i > 2)
            bonuses[2][i].setValue(10);
        else
            bonuses[2][i].setValue(9);
    }

    for (i = 0; i < 3; i++)
    {
        seals[i] = Token(100, "Seal");

    }
    numofSealsLeft = NUMSEALS;

    camelToken = Token (5, "Camel");

    MaxTokensForGoodsTs["Paper"] = NUMPAPER;
    MaxTokensForGoodsTs["Spice"] = NUMSPICE;
    MaxTokensForGoodsTs["Cloth"] = NUMCLOTH;
    MaxTokensForGoodsTs["Silver"] = NUMSILVER;
    MaxTokensForGoodsTs["Gold"] = NUMGOLD;
    MaxTokensForGoodsTs["Diamonds"] = NUMDIAMONDS;

    MaxTokensForBonuses[3] = NUM3S;
    MaxTokensForBonuses[4] = NUM4S;
    MaxTokensForBonuses[5] = NUM5S;

    shuffleBonus();
}

Bank::Bank(Bank & other)
{
    goodsTs =
    {{
        vector<Token>(NUMPAPER),
        vector<Token>(NUMSPICE),
        vector<Token>(NUMCLOTH),
        vector<Token>(NUMSILVER),
        vector<Token>(NUMGOLD),
        vector<Token>(NUMDIAMONDS)
    }};

    bonuses =
    {{
        vector<Token>(NUM3S),
        vector<Token>(NUM4S),
        vector<Token>(NUM5S)
    }};

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
    else if(goodYourTaking == "Cloth")
        kindofGoodYourTaking = 2;
    else if(goodYourTaking == "Silver")
        kindofGoodYourTaking = 3;
    else if(goodYourTaking == "Gold")
        kindofGoodYourTaking = 4;
    else if(goodYourTaking == "Diamonds")
        kindofGoodYourTaking = 5;
    // else throw error!

    int placeTakingFrom = MaxTokensForGoodsTs[goodYourTaking]-1;
    if (placeTakingFrom >= 0)
    {
        MaxTokensForGoodsTs[goodYourTaking]--;
        return &goodsTs[kindofGoodYourTaking][placeTakingFrom];
    }
    else
    {
        temp0->Token::setType(goodYourTaking);
        temp0->Token::setValue(0);
        return temp0;
    }
   
}

Token * Bank::takeBonusToken(int BonusTaking) //Pop Top
{
    int placeTakingFrom = MaxTokensForBonuses[BonusTaking];
    if(placeTakingFrom >= 0){
        Token * temp = &bonuses[BonusTaking-3][placeTakingFrom];
        MaxTokensForBonuses[BonusTaking]--;
        return temp;
    }
    else {
        temp0->Token::setType("Bonus");
        temp0->Token::setValue(2+BonusTaking);
        return temp0;
    }
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
    for(int i = 0; i < 6 ; i++)
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

    int i;
    for (i = 0; i < 7; i++)
    {
        int b3 = rand() % 7;
        swap(i, b3, 0);
    }
    for (i = 0; i < 6; i++)
    {
        int b4 = rand() % 6;
        swap(i, b4, 0);
    }
    for (i = 0; i < 5; i++)
    {
        int b5 = rand() % 5;
        swap(i, b5, 0);
    }

}

void Bank::swap (int a, int b, int c)
{
    Token temp = bonuses[c][a]
    bonuses[c][a]=bonuses[c][b];
    bonuses[c][b] = temp;
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

int Bank::isDepleted()
{
    int depletedTokens = 0;
    if(isGoodDepleted("Paper")) {
        depletedTokens++;
    }
    if(isGoodDepleted("Spice")) {
        depletedTokens++;
    }
    if(isGoodDepleted("Cloth")) {
        depletedTokens++;
    }
    if(isGoodDepleted("Silver")) {
        depletedTokens++;
    }
    if(isGoodDepleted("Gold")) {
        depletedTokens++;
    }
    if(isGoodDepleted("Diamonds")) {
        depletedTokens++;
    }
    return depletedTokens;
}
