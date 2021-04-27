/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#pragma once
#include <string>
#include <vector>
#include "Pokemon.h"
#include "Enumerators.h"

class Card {
protected:
	bool isDiscarded;	
	bool isPrizeCard;
	bool isOnBench;
	CardType cardType;
public:
	Card(CardType type) {
		this->cardType = type;
		isDiscarded = false;
		isPrizeCard = false;
		isOnBench = false;
	}
	~Card() {

	}

	void Discard() {
		this->isDiscarded = true;
	}

};

class PokemonCard : public Card{
private:
	Pokemon *p;
public:
	PokemonCard(Pokemon *pokemon): 
	Card(CardType::POKEMON){
		p = pokemon;
	}

	Pokemon* getPokemon(){return this->p;}

};

class TrainerCard : public Card{
private:
public:
	TrainerCard(): 
	Card(CardType::TRAINER){
	}
};

class EnergyCard : public Card{
private:
public:
	EnergyCard(): 
	Card(CardType::ENERGY){
	}
};

