#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

class State {

private:
    unsigned int deckSeed;
    unsigned int bonusSeed;

public:
    getDeckSeed() { return deckSeed; };
    getBonusSeed() { return bonusSeed; };

};

#endif // STATE_H_INCLUDED
