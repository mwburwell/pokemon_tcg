/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "ElementalType.h"
#include "Attack.h"

using namespace std;

/// <summary>
/// Pokemon
/// </summary>
class Pokemon {
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
	std::string name;
public:
	Pokemon(int cardIDNumber, std::string name, int maxHP, int retreatCost, PokemonCardType type) {
		setCardIDNumber(cardIDNumber);
		setName(name);
		setMaxHP(maxHP);
		this->cardType = type;
		setRetreatCost(retreatCost);
		setHitPoints(0);
		setIsPoisoned(false);
		setIsAsleep(false);
		setIsBurnt(false);
		setIsParalyzed(false);
		setIsConfused(false);
		this->statusIsAffected = false;
	}
	~Pokemon() {
		delete this;
	}

	std::string getName() { return name; }
	void setName(std::string s) {
		this->name = s;
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
		/* So that the Pokemon does not heal less than 0 hitpoints */
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

class Basic : public Pokemon {
private:
public:
	/// <summary>
	/// Basic Pokemon Derived class
	/// </summary>
	/// <param name="cardIDNumber">: The ID number of the Card</param>
	/// <param name="name">: The name of the Pokemon </param>
	/// <param name="maxHP">: The max HP of the Pokemon</param>
	/// <param name="retreatCost">: The cost to retreat </param>
	Basic(int cardIDNumber, std::string name, int maxHP, int retreatCost) : Pokemon(cardIDNumber, name, maxHP, retreatCost, PokemonCardType::BASIC) {

	}
};

class Stage_1 : public Pokemon {
private:
public:
	/// <summary>
	/// Stage 1 evolution type
	/// </summary>
	/// <param name="cardIDNumber">:  The ID number of the Card</param>
	/// <param name="name">:  The name of the Pokemon</param>
	/// <param name="maxHP">:  The max HP of the Pokemon</param>
	/// <param name="retreatCost">:  The cost to retreat</param>
	Stage_1(int cardIDNumber, std::string name, int maxHP, int retreatCost) : Pokemon(cardIDNumber, name, maxHP, retreatCost, PokemonCardType::STAGE_1) {

	}
};

class Stage_2 : public Pokemon {
private:
public:
	/// <summary>
	/// Stage 2 evolution Pokemon
	/// </summary>
	/// <param name="cardIDNumber">:  The ID number of the Card</param>
	/// <param name="name">:  The name of the Pokemon</param>
	/// <param name="maxHP">:  The maximum HP of the Pokemon</param>
	/// <param name="retreatCost">:  The retreat cost of the Pokemon</param>
	Stage_2(int cardIDNumber, std::string name, int maxHP, int retreatCost) : Pokemon(cardIDNumber, name, maxHP, retreatCost, PokemonCardType::STAGE_2) {

	}
};