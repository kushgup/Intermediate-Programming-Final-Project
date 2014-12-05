#include <iostream>
#include "assert.h"

#include "Bank.h"
#include "Deck.h"
#include "Field.h"

using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {

    Bank one = *new Bank();
    one.Bank::printBank();
    Field two = *new Field();
    two.Field::printField();

    Token * TakenPaper1 = one.Bank::takeTokenFromGoodTs("Gold");
    Token * TakenPaper2 = one.Bank::takeTokenFromGoodTs("Paper");
    Token * TakenBon3 = one.Bank::takeBonusToken(3);
    Bank three = * new Bank(one);
    Token * TakenSeal1 = three.Bank::takeSeal();

    //check previous things...
    assert(TakenPaper1->Token::getValue() == 6);
    assert(TakenPaper1->Token::getType() == "Gold");
    assert(TakenPaper2->Token::getValue() == 4);
    assert(TakenPaper2->Token::getType() == "Paper");
    assert(TakenBon3->Token::getValue() >=1 || TakenBon3->Token::getValue() <=3);
    assert(TakenSeal1->Token::getValue() == 100);
    
    Card x = *new Card ("Paper");
    Card y = *new Card ("Paper");
    
    assert(x==y);

    one.Bank::printBank();

    cout << "All Tests Pass" << endl;

    return 0;
}
