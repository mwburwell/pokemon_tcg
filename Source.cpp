/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "DerivedPokemon.h"


int main() {
	std::vector<Pokemon*> pokemonDeck;
	std::vector<Element*> elementType;
	pokemonDeck.push_back(new Squirtle);
	pokemonDeck.push_back(new Wartortle);
	pokemonDeck.push_back(new Blastoise);
	pokemonDeck.push_back(new Eevee);
	pokemonDeck[0];
	Squirtle s;

	std::vector<PokemonCard*> pokeCards;
	pokeCards.push_back(new PokemonCard(new Squirtle));
	ElementType e = pokeCards[0]->getPokemon()->Attack1()->getElementAttackType();
	//Element *e = p->getElement();
	


	cout << pokemonDeck[0]->getName() << " uses: " << pokemonDeck[0]->Attack1()->getAttackName() << endl;

	for (int i = 0; i < 4; i++) {
		std::cout << "Pokemon: " << pokemonDeck[i]->getName() << std::endl;
	}

	return 0;
}
