//
//  Token.cpp
//  pg7b
//
//  Created by Edmund Connor on 11/23/14.
//  Copyright (c) 2014 Edmund Connor. All rights reserved.
//

#include "Token.h"
#include <stdio.h>
#include <iostream>

void Token::printToken() const
{
    cout << TypeOfToken << ":" << value;
}
