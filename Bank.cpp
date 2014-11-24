//
//  Bank.cpp
//  pg7b
//
//  Created by Edmund Connor on 11/19/14.
//  Copyright (c) 2014 Edmund Connor. All rights reserved.
//

#include "Bank.h"
#include <stdio.h>
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

Bank::Bank()
{
    
    for (int i = 0; i < NUMPAPER; i++)
    {
        bank[0][i] = *new Token (1, "Paper");
        if(i == 8)
            bank[0][i].Token::setValue(4);
        if(i == 7)
            bank[0][i].setValue(3);
        if(i == 6)
            bank[0][i].setValue(2);
    }
    
    for (int i = 0; i < NUMSPICE; i++)
    {
        bank[1][i] = *new Token (1, "Spice");
        if(i == 6)
            bank[1][6].setValue(5);
        if(i == 5 || i == 4)
            bank[1][i].setValue(3);
        if(i == 3 || i == 2)
            bank[1][i].setValue(2);
    }
    
    for (int i = 0; i < NUMCLOTH; i++)
    {
        bank[2][i] = *new Token (1, "Cloth");
        if(i == 6)
            bank[2][6].setValue(5);
        if(i == 5 || i == 4)
            bank[2][i].setValue(3);
        if(i == 3 || i == 2)
            bank[2][i].setValue(2);
    }
    
    for (int i = 0; i < NUMSILVER; i++)
    {
        bank[3][i] = *new Token (5, "Silver");
    }
    
    for (int i = 0; i < NUMGOLD; i++)
    {
        bank[4][i] = *new Token (6, "Gold");
        if(i <= 2)
            bank[4][i].setValue(5);
    }
    
    for (int i = 0; i < NUMDIAMONDS; i++)
    {
        bank[5][i] = *new Token (6, "Diamonds");
        if(i <= 2)
            bank[5][i].setValue(5);
    }
    
    for (int i = 0; i < NUM3S; i++)
    {
        bonuses[0][i] = *new Token (2, "Bonus3");
        if (i < 2)
            bonuses[0][i].setValue(1);
        if (i > 4)
            bonuses[0][i].setValue(3);
    }
    
    for (int i = 0; i < NUM4S; i++)
    {
        bonuses[1][i] = *new Token (5, "Bonus4");
        if (i < 2)
            bonuses[0][i].setValue(4);
        if (i > 3)
            bonuses[0][i].setValue(6);
    }
    
    for (int i = 0; i < NUM5S; i++)
    {
        bonuses[2][i] = *new Token (9, "Bonus5");
        if (i < 2)
            bonuses[0][i].setValue(8);
        if (i > 2)
            bonuses[0][i].setValue(10);
    }
    
    for (int i = 0; i < 3; i++)
    {
        seals[i] = *new Token (0, "Seal");
    }
    
    camelToken = *new Token (0, "Camel");
}

Bank::Bank(Bank & other)
{
    for(int i = 0; i< 6; i++)
    {
        for(int j = 0; j< 9; j++)
        {
            bank[i][j] = other.bank[i][j];
        }
    }
    for(int i = 0; i< 3; i++)
    {
        for(int j = 0; j< 7; j++)
        {
            bonuses[i][j] = other.bonuses[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        seals[i] = other.seals[i];
    }
    camelToken = other.camelToken;
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

Token Bank::takeFromBank(int good) //Pop Top
{
    int size = sizeof(bank[good]);
    Token temp = bank[good][size];
    //bank[good][size] = NULL; why doesn't this work???? trying to pop top off
    return temp;
    
}

Token Bank::takeBonus(int kind) //Pop Top
{
    int size = sizeof(bonuses[kind]);
    Token temp = bank[kind][size];
    //bonuses[kind][size] = NULL; why doesn't this work???? trying to pop top off
    return temp;
}

Token Bank::takeSeal()
{
    int size = sizeof(seals);
    Token temp = seals[size];
    //seals[size] = NULL; why doesn't this work???? trying to pop top off
    return temp;
}

Token Bank::getCamelToken()
{
    return camelToken;
}

void Bank::printBank()
{
    cout << "**************************************************" << endl;
    for(int i; i< 5 ;i++)
    {
        cout << bank[i][0].getType() << " Tokens: \t\t";
        for (int k = 0; k< sizeof(bank[i]); i++)
        {
            cout << bank[i][k].getValue() << " ";
        }
        cout << endl;
    }
    
    for(int i; i< 3 ;i++)
    {
        cout << bonuses[i][0].getType() << " Tokens: \t\t";
        for (int k = 0; k< sizeof(bonuses[i]); i++)
        {
            cout << "• ";
        }
        cout << endl;
    }
    cout << "Seals: \t\t\t";
    for(int i = 0; i< sizeof(seals); i++)
    {
        cout << "• ";
    }
    cout << "Camel Token: \t\t5"<<endl;
    cout << endl;
}










