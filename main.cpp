//
//  main.cpp
//  pg7b
//
//  Created by Edmund Connor on 11/19/14.
//  Copyright (c) 2014 Edmund Connor. All rights reserved.
//

#include <iostream>
#include "Bank.h"

int main(int argc, const char * argv[]) {
   
    Bank one = *new Bank();
    one.Bank::printBank();
    return 0;
}
