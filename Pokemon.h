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

/// <summary>
/// Pokemon
/// </summary>
class Pokemon : public Card {
private:
	int cardIDNumber;
	int hitPoints;
	int maxHP;
	PokemonCardType cardType;
	int retreatCost;
	bool statusIsAffected;
	bool isPoisoned;
	bool isAsleep;
	bool isBurnt;
	bool isConfused;
	bool isParalyzed;
public:
	Pokemon(int cardIDNumber, std::string name, int maxHP, int retreatCost, PokemonCardType type) : Card(name, CardType::POKEMON) {
		setCardIDNumber(cardIDNumber);
		setMaxHP(maxHP);
		this->cardType = type;
		setRetreatCost(retreatCost);
		setHitPoints(0);
		this->statusIsAffected = false;
		this->isPoisoned = false;
		this->isAsleep = false;
		this->isBurnt = false;
		this->isConfused = false;
		this->isParalyzed = false;
	}
	~Pokemon() {
		delete this;
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
	void setRetreatCost(int cost) {
		if (cost < 0)
			throw std::underflow_error("Retreat cost can not be less than 0");
		if (cost > 5)
			throw std::overflow_error("The maximum cost for retreat is 5");
		this->retreatCost = cost;
	}

	/// <summary>
	/// If pokemon is poisoned than heal them
	/// </summary>
	/// <returns> true/false </returns>
	bool getIsPoisoned() { return this->isPoisoned; }
	void setIsPoisoned(bool effected) {
		this->isPoisoned = effected;
	}

	// confusion
	bool getIsConfused() { return this->isConfused; }
	void setIsConfused(bool effected) {
		this->isConfused = effected;
	}

	bool getIsBurnt() { return this->isBurnt; }
	void setIsBurnt(bool effected) {
		this->isBurnt = effected;
	}

	bool getIsAsleep() { return this->isAsleep; }
	void setIsAsleep(bool effected) {
		this->isAsleep = effected;
	}

	bool getIsParalyzed() { return this->isParalyzed; }
	void setIsParalyzed(bool effected) {
		this->isParalyzed = effected;
	}

	//virtual void setIsPoisoned(bool ispoison) = 0;
	virtual Attack* Attack1() = 0;
	virtual Attack* Attack2() = 0;
	virtual Attack* Attack3() = 0;

};


/// /////////////////////////////////////////////////////////////// <summary> ///////////////////////////////////////////////////////////////
///										Second Set of Base class for three separte types of Pokemon Cards 
/// ////////////////////////////////////////////////////////////// </summary> ///////////////////////////////////////////////////////////////
class Basic : public Pokemon {
private:
public:
	Basic(int cardIDNumber, std::string name, int maxHP, int retreatCost) : Pokemon(cardIDNumber, name, maxHP, retreatCost, PokemonCardType::BASIC) {

	}
	virtual Attack* Attack1() = 0;

};

class Stage_1 : public Pokemon {
private:
public:
	Stage_1(int cardIDNumber, std::string name, int maxHP, int retreatCost) : Pokemon(cardIDNumber, name, maxHP, retreatCost, PokemonCardType::EVOLUTION) {

	}
	virtual void setRetreatCost(int cost) = 0;
	virtual void setIsPoisoned(bool ispoison) = 0;

};

class Stage_2 : public Pokemon {
private:
public:
	Stage_2(int cardIDNumber, std::string name, int maxHP, int retreatCost) : Pokemon(cardIDNumber, name, maxHP, retreatCost, PokemonCardType::SPECIAL) {

	}
	virtual void setRetreatCost(int cost) = 0;
	virtual void setIsPoisoned(bool ispoison) = 0;

};



///////////////////////////////////////////////////////////////// <summary> ///////////////////////////////////////////////////////////////
///																DERIVED POKEMON
///////////////////////////////////////////////////////////////// </summary> //////////////////////////////////////////////////////////////

/// <summary>
/// <para>Card Type: Basic</para>
/// <para>Element Type: Water</para>
/// <para>Weakness: Lightning</para>
/// <para>Max HP: 50</para>
/// <para>Resistance: None</para>
/// <para>Attacks:</para> 
/// <para>Bubble:
/// Hitpoints: 20
///		- Description: Flip a coin, if heads the defending Pokemon is now paralyzed
///		- Elemental Cost: 
///		- Colorless Cost: 1
///		- Element Type: Water
///		- Status Effect: Paralysis 50/50
/// </para>
/// <para> WaterGun
/// Hitpoints: 20 
///		- Description: Shoots water gun.
///		- Elemental Cost: 1
///		- Colorless Cost: 1
///		- Element Type: Water
/// </para>
/// <returns> Bubble Attack </returns>
/// </summary>
class Squirtle : public Basic, public Water {
private:
	Attack* bubble;
	Attack* waterGun;
public:
	Squirtle() : Basic(7, "Squirtle", 50, 1) {
		bubble = new Bubble(0, 1, 0);
		waterGun = new WaterGun(20, 1, 1);
	}
	~Squirtle() {
		delete bubble;
		delete waterGun;
		bubble = NULL;
		waterGun = NULL;
	}

	Attack* Attack1() { return this->bubble; }
	Attack* Attack2() { return this->waterGun; }
	Attack* Attack3() { return NULL; }
};


class Wartortle : public Stage_1, public Water {
private:
	Attack* Bubble;
	Attack* Surf;
public:
	Wartortle() : Stage_1(8, "Wartortle", 80, 2), Water() {
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
	Blastoise() : Stage_2(9, "Blastoise", 80, 3), Water() {

	}
	~Blastoise() {
	}


};

class Eevee : public Basic, public Colorless {
private:
public:
	Eevee() : Basic(133, "Eevee", 80, 1), Colorless::Colorless(Element::FIGHTING) {
	}
	//~Eevee() {
	//}


};
