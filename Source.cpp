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
	pokemonCards.push_back(new PokemonCard(new Wartortle));
	pokemonCards.push_back(new PokemonCard(new Blastoise));
	pokemonCards.push_back(new PokemonCard(new Eevee));

	// make pokemon go to sleep
	pokemonCards[0]->getPokemon()->setIsAsleep(true);

	// check if pokemon is asleep if so then don't wake them
	if( pokemonCards[0]->getPokemon()->getIsAsleep()){
		cout << "Don't wake "<< pokemonCards[0]->getPokemon()->getName() << ". It is sleeping. " << endl;
	}

	// print all pokemon in the pokemonCards and see if they are asleep or not
	for(int i = 0; i < pokemonCards.size(); i++){
		cout << "Pokemon: \t" << pokemonCards[i]->getPokemon()->getName() << endl;
		cout << "Asleep: \t" << pokemonCards[i]->getPokemon()->getIsAsleep_toString() << endl << endl; 
	}

	return 0;
}
