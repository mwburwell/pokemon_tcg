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

	bool getIsPoisoned() { return this->isPoisoned; }
	void setIsPoisoned(bool effected) {
		this->isPoisoned = effected;
	}
	
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

	virtual Attack* Attack1() = 0;
	virtual Attack* Attack2() = 0;
	virtual Attack* Attack3() = 0;

};


// /////////////////////////////////////////////////////////////// <summary> ///////////////////////////////////////////////////////////////
//										Second Set of Base class for three separte types of Pokemon Cards 
// ////////////////////////////////////////////////////////////// </summary> ///////////////////////////////////////////////////////////////
class Basic : public Pokemon {
private:
public:
	Basic(int cardIDNumber, std::string name, int maxHP, int retreatCost) : Pokemon(cardIDNumber, name, maxHP, retreatCost, PokemonCardType::BASIC) {

	}
	virtual Attack* Attack1() = 0;
	virtual Attack* Attack2() = 0;
	virtual Attack* Attack3() = 0;

};

class Stage_1 : public Pokemon {
private:
public:
	Stage_1(int cardIDNumber, std::string name, int maxHP, int retreatCost) : Pokemon(cardIDNumber, name, maxHP, retreatCost, PokemonCardType::EVOLUTION) {

	}
	virtual Attack* Attack1() = 0;
	virtual Attack* Attack2() = 0;
	virtual Attack* Attack3() = 0;

};

class Stage_2 : public Pokemon {
private:
public:
	Stage_2(int cardIDNumber, std::string name, int maxHP, int retreatCost) : Pokemon(cardIDNumber, name, maxHP, retreatCost, PokemonCardType::SPECIAL) {

	}
	virtual Attack* Attack1() = 0;
	virtual Attack* Attack2() = 0;
	virtual Attack* Attack3() = 0;

};



///////////////////////////////////////////////////////////////// <summary> ///////////////////////////////////////////////////////////////
///																DERIVED POKEMON
///////////////////////////////////////////////////////////////// </summary> //////////////////////////////////////////////////////////////

/// <summary>
/// <para>Squirtle - BASIC </para>
/// <para>Max HP: 50</para>
/// <para>Attack1 - Bubble, 0 hitpoints, 1 water, 0 colorlesss, can cause paralysis</para>
/// <para>Attack2 - WaterGun, 20 hitpoints, 1 water, 1 colorless</para>
/// <para>Element Type: Water</para>
/// <para>Weakness: Lightning</para>
/// <para>Resistance: None</para>
/// </summary>
/// <param name = "None"> None </param>
/// <returns> A Squirtle </returns>
class Squirtle : public Basic, public Water {
private:
	Attack* bubble;
	Attack* waterGun;
public:
	/// <param name = "None"> No parameters </param>
	Squirtle() : Basic(7, "Squirtle", 50, 1) {
		this->bubble = new Bubble(0, 1, 0);
		this->waterGun = new WaterGun(20, 1, 1);
		Attack s();
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

/// <summary>
/// <para>Wartortle - STAGE_1 </para>
/// <para>Max HP: 80</para>
/// <para>Attack1 - Bubble, 20 hitpoints, 1 water, 1 colorlesss, can cause paralysis</para>
/// <para>Attack2 - WaterGun, 50 hitpoints, 1 water, 2 colorless</para>
/// <para>Attack3 - NULL</para>
/// <para>Element Type: Water</para>
/// <para>Weakness: Lightning</para>
/// <para>Resistance: None</para>
/// </summary>
/// <param name = "None"> None </param>
/// <returns> A Squirtle </returns>
class Wartortle : public Stage_1, public Water {
private:
	Attack* bubble;
	Attack* surf;
public:
	Wartortle() : Stage_1(8, "Wartortle", 80, 2), Water() {
		this->bubble = new Bubble(20, 1, 1);
		this->surf = new Surf(50, 1, 2);

	~Wartortle() {
		delete bubble;
		delete surf;
		Bubble = NULL;
		Surf = NULL;
	}

	Attack* Attack1() { return this->bubble; }
	Attack* Attack2() { return this->surf; }
	Attack* Attack3() { return NULL; }
};

/// <summary>
/// <para>Blastoise - STAGE_2 </para>
/// <para>Max HP: 180</para>
/// <para>Attack1 - </para>
/// <para>Attack2 - </para>
/// <para>Attack3 - NULL</para>
/// <para>Element Type: Water</para>
/// <para>Weakness: Lightning</para>
/// <para>Resistance: None</para>
/// </summary>
/// <param name = "None"> None </param>
/// <returns> A Blastoise </returns>
class Blastoise : public Stage_2, public Water {
private:
	Attack* attack1;
public:
	Blastoise() : Stage_2(9, "Blastoise", 180, 3), Water() {
	}
	~Blastoise() {
	}

	Attack* Attack1() { return NULL; }
	Attack* Attack2() { return NULL; }
	Attack* Attack3() { return NULL; }

};

/// <summary>
/// <para>Eevee - BASIC </para>
/// <para>Max HP: 80</para>
/// <para>Attack1 - </para>
/// <para>Attack2 - </para>
/// <para>Attack3 - NULL</para>
/// <para>Element Type: Colorless</para>
/// <para>Weakness: Fighting</para>
/// <para>Resistance: None</para>
/// </summary>
/// <param name = "None"> None </param>
/// <returns> An Eevee </returns>
class Eevee : public Basic, public Colorless {
private:
public:
	Eevee() : Basic(133, "Eevee", 80, 1), Colorless::Colorless(Element::FIGHTING) {
	}
	~Eevee() {
	}

	Attack* Attack1() { return NULL; }
	Attack* Attack2() { return NULL; }
	Attack* Attack3() { return NULL; }
};
