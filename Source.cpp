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

	std::vector<Pokemon*> pokemonDeck;
	pokemonDeck.push_back(new Geodude());
	pokemonDeck.push_back(new Squirtle());

	return 0;
}
