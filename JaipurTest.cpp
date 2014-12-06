#include "Game.h"
#include <cassert>

int main() {

	Game my_game;

	assert(my_game.field.market.at(0)->identifier == "Camel");
	assert(my_game.field.market.at(1)->identifier == "Camel");
	assert(my_game.field.market.at(2)->identifier == "Camel");
	assert(my_game.field.market.at(3)->identifier == "Paper");
	assert(my_game.field.market.at(4)->identifier == "Camel");
	assert(my_game.players[0]->herd.size() == 0);
	assert(my_game.players[0]->hand.size() == 5);
	assert((**(my_game.players[0]->hand.get(0))).getIdentifier() == "Diamonds");
	assert((**(my_game.players[0]->hand.get(1))).getIdentifier() == "Paper");
	assert((**(my_game.players[0]->hand.get(2))).getIdentifier() == "Spice");
	assert((**(my_game.players[0]->hand.get(3))).getIdentifier() == "Diamonds");
	assert((**(my_game.players[0]->hand.get(4))).getIdentifier() == "Gold");

    my_game.players[0]->takeCamels(Move( &(my_game.field) ));
    assert(my_game.players[0]->herd.size() == 4);

    my_game.field.refillMarket();
    assert(my_game.field.market.at(0)->identifier == "Paper");
	assert(my_game.field.market.at(1)->identifier == "Paper");
	assert(my_game.field.market.at(2)->identifier == "Camel");
	assert(my_game.field.market.at(3)->identifier == "Spice");
	assert(my_game.field.market.at(4)->identifier == "Gold");


    my_game.players[1]->takeCard(Move( &(my_game.field), my_game.players[1]->hand, 'a'));
    assert(my_game.players[1]->hand.size() == 5);
    //assert(my_game.players[0]->herd.size() == 4);




	//hardcoded srand(11)
	//temporarily made all private members and functions public for ease of testing

    cout << "all tests passed!" << endl;
    cout << "thank you for coming. Have a nice day." << endl;



	return 0;
}
