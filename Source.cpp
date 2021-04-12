/***************************************************************************************************************************
 Class:  CSCI201-0CC-C1-202030-VI-16R
 Program: Pokemon The Card Game
 Instructor:  Kristopher Roberts
 Auther:  Michael Burwell
 Date:  04/10/2021
****************************************************************************************************************************/
/****************************************************************************************************************************
/////////////////////							Pokemon The Card Game Main 								/////////////////////
****************************************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
void print(ElementalType* element);


int main() {
	std::vector<Pokemon*> pokemonDeck;
	pokemonDeck.push_back(new Squirtle);
	pokemonDeck.push_back(new Wartortle);
	pokemonDeck.push_back(new Blastoise);
	pokemonDeck.push_back(new Eevee);


	Pokemon *squirt = new Squirtle;
	ElementalType* s = new Squirtle;
	squirt->Attack1()->getElementAttackType();

	return 0;
}

void print(ElementalType* element) {
	std::cout << "Attack Type: " << elementNames[element->getAttackType()] << std::endl;
	std::cout << "Weakness: " << elementNames[element->getWeaknessType()] << std::endl;
	std::cout << "Weakness Multiplier: " << element->getWeaknessMultiplier() << std::endl;
	std::cout << "Resistance: " << elementNames[element->getResistanceType()] << std::endl;
	std::cout << "Resistance Multiplier: " << element->getResistanceMultiplier() << std::endl << std::endl;
}