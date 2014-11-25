//
//  Bank.cpp
//  pg7b
//
//  Created by Edmund Connor on 11/19/14.
//  Copyright (c) 2014 Edmund Connor. All rights reserved.
//

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

Bank::Bank()
{
    
    for (int i = 0; i < NUMPAPER; i++)
    {
        bank[0][i] = *new Token ();
        bank[0][i].Token::setType("Paper");
        bank[0][i].Token::setValue(1);
        if(i == 8)
            bank[0][i].Token::setValue(4);
        if(i == 7)
            bank[0][i].Token::setValue(3);
        if(i == 6)
            bank[0][i].Token::setValue(2);
        
    }
    
    for (int i = 0; i < NUMSPICE; i++)
    {
        bank[1][i] = *new Token ();
        bank[1][i].Token::setType("Spice");
        if(i == 6)
            bank[1][6].Token::setValue(5);
        else if(i == 5 || i == 4)
            bank[1][i].Token::setValue(3);
        else if(i == 3 || i == 2)
            bank[1][i].Token::setValue(2);
        else
            bank[1][i].setValue(1);
    }
    
    for (int i = 0; i < NUMCLOTH; i++)
    {
        bank[2][i] = *new Token ();
        bank[2][i].Token::setType("Cloth");
        if(i == 6)
            bank[2][6].Token::setValue(5);
        else if(i == 5 || i == 4)
            bank[2][i].Token::setValue(3);
        else if(i == 3 || i == 2)
            bank[2][i].setValue(2);
        else
            bank[2][i].Token::setValue(1);
    }
    
    for (int i = 0; i < NUMSILVER; i++)
    {
        bank[3][i] = *new Token ();
        bank[3][i].Token::setValue(5);
        bank[3][i].Token::setType("Silver");
    }
    
    for (int i = 0; i < NUMGOLD; i++)
    {
        bank[4][i] = *new Token ();
        bank[4][i].Token::setType("Gold");
        if(i <= 2)
            bank[4][i].Token::setValue(5);
        else
            bank[4][i].Token::setValue(6);
    }
    
    for (int i = 0; i < NUMDIAMONDS; i++)
    {
        bank[5][i] = *new Token ();
        bank[5][i].Token::setType("Diamonds");
        if(i <= 2)
            bank[5][i].Token::setValue(5);
        else
            bank[5][i].Token::setValue(7);
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
        seals[i] = *new Token ();
        seals[i].Token::setType("Seal");
        seals[i].Token::setValue(100);
    }
    
    camelToken = *new Token ();
    camelToken.Token::setType("Camel");
    camelToken.Token::setValue(5);
    
    this->shuffleBonus();
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
    //error catching
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
    cout << "Bank **********************************************" << endl;
    for(int i=0; i< 6 ;i++)
    {
        int num_elements = sizeof( bank[i] ) / sizeof( bank[i][0] );
        if(bank[i][0].getType() == "Diamonds")
            cout << bank[i][0].getType() << " Tokens: \t";
        else
            cout << bank[i][0].getType() << " Tokens: \t\t";
        for (int k = 0; k< num_elements; k++)
        {
            int toBePrinted = bank[i][k].getValue();
            if(toBePrinted)
                cout << toBePrinted << " ";
        }
        cout << endl;
    }
    
    for(int i=0; i< 3 ;i++)
    {
        int num_elements = sizeof( bonuses[i] ) / sizeof( bonuses[i][0] );
        cout << bonuses[i][0].getType() << " Tokens: \t\t";
        for (int k = 0; k< num_elements; k++)
        {
            int toBePrinted = bonuses[i][k].getValue();
            if(toBePrinted)
                cout << "• ";
        }
        cout << endl;
    }
    cout << "Seals: \t\t\t\t";
    int numseals = sizeof( seals ) / sizeof( seals[0] );
    for(int i = 0; i< numseals; i++)
    {
        int toBePrinted = seals[i].getValue();
        if(toBePrinted)
            cout << "• ";
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






