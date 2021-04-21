/***************************************************************************************************************************
 Class:  CSCI201-0CC-C1-202030-VI-16R
 Program: Pokemon The Card Game
 Instructor:  Kristopher Roberts
 ***************************************************************************************************************************/
/****************************************************************************************************************************
/////////////////////							Pokemon The Card Game Main 								/////////////////////
****************************************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "DerivedPokemon.h"


int main() {
	std::vector<Pokemon*> pokemonDeck;
	pokemonDeck.push_back(new Squirtle);
	pokemonDeck.push_back(new Wartortle);
	pokemonDeck.push_back(new Blastoise);
	pokemonDeck.push_back(new Eevee);

	for (int i = 0; i < 4; i++) {
		std::cout << "Pokemon: " << pokemonDeck[i]->getName() << std::endl;
	}

	return 0;
}
