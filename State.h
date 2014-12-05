#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

class State {

private:
    unsigned int deckSeed;
    unsigned int bonusSeed;

public:
    int getDeckSeed() { return deckSeed; };
    void setDeckSeed(int seed) { this->deckSeed = seed; };
    int getBonusSeed() { return bonusSeed; };
    void setBonusSeed(int seed) {this->bonusSeed = seed; };

};

#endif // STATE_H_INCLUDED
