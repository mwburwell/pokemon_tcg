/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "DerivedPokemon.h"


int main() {

	std::vector<PokemonCard*> pokemonCards;
	pokemonCards.push_back(new PokemonCard(new Squirtle));

	ElementType e = pokemonCards[0]->getPokemon()->Attack1()->getElementAttackType();
	pokemonCards[0]->getPokemon()->setIsAsleep(true);

	if( pokemonCards[0]->getPokemon()->getIsAsleep()){
		cout << "Don't wake "<< pokemonCards[0]->getPokemon()->getName() << ". It is sleeping. " << endl;
	}

	// for (int i = 0; i < 4; i++) {
	// 	std::cout << "Pokemon: " << pokemonCards[i]->getPokemon()->getName() << std::endl;
	// }

	return 0;
}
