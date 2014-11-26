/*
This class defines the abstract base class Player.
It has a bunch of instance data that a player has, and functions pertaining to decision making the turn
This class will be inherited by HumanPlayer and AIPlayer
*/

#ifndef _PLAYER_H
#define _PLAYER_H

class Player {

protected:

	String name; //store the name of the player
	OList<Card> hand; //separate linked list of resource cards for the hand
	OList<Card> camels; //separate linked list of camels
	int points; //keep track of points, don't have a container to store tokens since we don't have a class for that
	int seals; //keep track of how many seals the player has

public:
	
	string getName() { return name; };
	int handSize() { return hand.size(); };
	int numCamels() { return camels.size(); };
	virtual void makeMove() = 0; //called from Game, decides which action to take on the turn
	
protected:

	void takeCamels(); //this method can be defined within Player itself since it will be the same for both human and ai players
	void takeCard(); //option 1, take a single card from market
	void exchange(); //option 2, take multiple cards from market and exchange from hand and/or camels
	void sellCards(); //option 3, sell cards from the hand
};

//exchange, take, sell and takecamels are all the same for humans and computers, just the "decision" in "move" is different

#endif
