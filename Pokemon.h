/***************************************************************************************************************************
 Class:  CSCI201-0CC-C1-202030-VI-16R
 Program: Pokemon The Card Game
 Instructor:  Kristopher Roberts
 Auther:  Michael Burwell
 Date:  04/10/2021
****************************************************************************************************************************/
/****************************************************************************************************************************
/////////////////////								Pokemon Header File									/////////////////////
****************************************************************************************************************************/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ElementalType.h"
#include "Attack.h"
#include "Enumerators.h"
#include "Card.h"

using namespace std;


class Pokemon : public Card {
public:
	int cardIDNumber;
	int hitPoints;
	int maxHP;
	PokemonCardType cardType;
	int retreatCost;
	bool isPoisoned;
	bool isAsleep;
	bool isBurnt;
	bool isConfused;
	bool isParalyzed;
public:
	Pokemon(int cardIDNumber, std::string name, int maxHP, PokemonCardType type) : Card(name, CardType::POKEMON) {
		setCardIDNumber(cardIDNumber);
		setMaxHP(maxHP);
		this->cardType = type;
		setHitPoints(0);
		this->isPoisoned = false;
		this->isAsleep = false;
		this->isBurnt = false;
		this->isConfused = false;
		this->isParalyzed = false;
	}

	int getCardIDNumber() { return cardIDNumber; }
	void setCardIDNumber(int idNumber) {
		if (idNumber < 0)
			throw std::underflow_error("Card number can not be less than 0");
		this->cardIDNumber = idNumber;
	}

	int getMaxHP() {
		return this->maxHP;
	}
	void setMaxHP(int newHP) {
		if (newHP <= 0)
			throw std::underflow_error("Pokemon can not have 0 max HP.");
		this->maxHP = newHP;
	}

	int getHitPoints() {
		return this->hitPoints;
	}
	void setHitPoints(int hitPoints) {
		if (hitPoints < 0)
			throw std::underflow_error("Hit points can not be less than 0.");
		this->hitPoints = hitPoints;
	}

	void Hit(int hit) {
		this->hitPoints += hit;
	}
	void Heal(int healingItem) {
		/* So that the Pokemon does not heal less than 0 */
		if (healingItem > getHitPoints())
			this->hitPoints -= (healingItem - getHitPoints());
		else
			this->hitPoints -= healingItem;
	}

	int getRetreatCost() {
		return retreatCost;
	}
	virtual void setRetreatCost(int cost) = 0;
	virtual void setIsPoisoned(bool ispoison) = 0;
	virtual Attack *Attack1() = 0;

};


/// /////////////////////////////////////////////////////////////// <summary> ///////////////////////////////////////////////////////////////
///										Second Set of Base class for three separte types of Pokemon Cards 
/// ////////////////////////////////////////////////////////////// </summary> ///////////////////////////////////////////////////////////////
class Basic : public Pokemon {
private:
public:
	Basic(int cardIDNumber, std::string name, int maxHP) : Pokemon(cardIDNumber, name, maxHP, PokemonCardType::BASIC) {

	}
	virtual void setRetreatCost(int cost) = 0;
	virtual void setIsPoisoned(bool ispoison) = 0;
	virtual Attack *Attack1() = 0;

};

class Stage_1: public Pokemon {
private:
public:
	Stage_1(int cardIDNumber, std::string name, int maxHP) : Pokemon(cardIDNumber, name, maxHP, PokemonCardType::EVOLUTION) {

	}
	virtual void setRetreatCost(int cost) = 0;
	virtual void setIsPoisoned(bool ispoison) = 0;

};

class Stage_2 : public Pokemon {
private:
public:
	Stage_2(int cardIDNumber, std::string name, int maxHP) : Pokemon(cardIDNumber, name, maxHP, PokemonCardType::SPECIAL) {

	}
	virtual void setRetreatCost(int cost) = 0;
	virtual void setIsPoisoned(bool ispoison) = 0;

};



///////////////////////////////////////////////////////////////// <summary> ///////////////////////////////////////////////////////////////
///																DERIVED POKEMON
///////////////////////////////////////////////////////////////// </summary> //////////////////////////////////////////////////////////////
class Squirtle : public Basic, public Water {
public:
	Attack *Bubble;
	Attack *WaterGun;
public:
	Squirtle() : Basic(7,"Squirtle", 50) {
		Bubble = new Attack(
			"Bubble",					// name of attack
			"Flip a coin, if heads the defending Pokemon is now paralyzed",		// attack description
			0,							// hitpoints attack causes
			1,							// number of required elemental energy card cost
			0,							// number of required colorless energy card cost
			Element::WATER,				// attack element type
			StatusEffects::PARALYSIS);	// causes paralysis	
		
		WaterGun = new Attack(
			"Water Gun",				// attack name
			"Shoots Water Gun",			// attack description
			20,							// hitpoints attack causes
			1,							// number of required elemental energy card cost
			1,							// number of required colorless energy card cost
			Element::WATER);			// attack element type
	}
	~Squirtle() {
		delete Bubble;
		delete WaterGun;
		Bubble = NULL;
		WaterGun = NULL;
	}

	Attack* Attack1() { return this->Bubble; }
	Attack* Attack2() { return this->WaterGun; }
	virtual void setRetreatCost(int cost) {
		this->retreatCost = 1;
	}
	virtual void setIsPoisoned(bool ispoison) {
		this->isPoisoned = ispoison;
	}
};

class Wartortle : public Stage_1, public Water {
private:
	Attack* Bubble;
	Attack* Surf;
public:
	Wartortle() : Stage_1(8,"Wartortle", 80), Water() {
		Bubble = new Attack(
			"Bubble",					// name of attack
			"Flip a coin, if heads the defending Pokemon is now Paralyzed",		// attack description
			20,							// hitpoints attack causes
			1,							// number of required elemental energy card cost
			1,							// number of required colorless energy card cost
			Element::WATER,				// attack element type
			StatusEffects::PARALYSIS);	// causes paralysis
		
		
		Surf = new Attack(
			"Surf",						// name of attack
			"Wartortle uses Surf",		// attack description
			50,							// hitpoints attack causes
			1,							// number of required elemental energy card cost
			2,							// number of required colorless energy card cost
			Element::WATER);				// attack element type
	}
	~Wartortle() {
		delete Bubble;
		delete Surf;
		Bubble = NULL;
		Surf = NULL;
	}


};

class Blastoise : public Stage_2, public Water {
private:
public:
	Blastoise() : Stage_2(9,"Blastoise", 80), Water() {

	}
	~Blastoise() {
	}


};

class Eevee : public Basic, public Colorless {
private:
public:
	Eevee() : Basic(133, "Eevee", 80), Colorless::Colorless(Element::FIGHTING) {
	}
	//~Eevee() {
	//}


};
