#include <stdio.h>
#include "PlayerHuman.h"
#include "Field.h"
#include "Bank.h"
#include <cassert>

int main() {

    Bank b1 = *new Bank();
    Field f1 = *new Field();
    
    PlayerHuman p1 = *new PlayerHuman("EJ" , &f1, &b1);
    
    assert(p1.PlayerHuman::getName() == "EJ");
    assert(p1.PlayerHuman::handSize()==0);
    assert(p1.PlayerHuman::numCamels()==0);
    assert(p1.PlayerHuman::countPts()==0);
    assert(p1.PlayerHuman::countSeals()==0);
    
    
    std::cout << "all tests pass" << endl;
    
    

	return 0;
}
