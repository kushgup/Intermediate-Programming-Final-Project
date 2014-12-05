#include "Player.h"

#ifndef PLAYERCOMP_H_INCLUDED
#define PLAYERCOMP_H_INCLUDED

using std::string;

class PlayerComp: public Player {

public:
    PlayerComp(string nm, Field * fd, Bank * bk): Player::Player(nm, fd, bk) { }

};


#endif // PLAYERCOMP_H_INCLUDED
