#ifndef _PLAYERCOMP_H_INCLUDED
#define _PLAYERCOMP_H_INCLUDED

#include "Player.h"

class PlayerComp: public Player {

public:

    PlayerComp(string nm, Field * fd, Bank * bk): Player::Player(nm, fd, bk) { }
    ~PlayerComp();
    
    void makeMove();
};


#endif // PLAYERCOMP_H_INCLUDED
