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
#include "Enumerators.h"

/* Enumerations and string maps for Element Types */
enum class ElementType { PSYCHIC, COLORLESS, FIRE, GRASS, WATER, LIGHTNING };
std::map<ElementType, std::string> elementTypeNames = {
	{ElementType::PSYCHIC, "PSYCHIC"},
	{ElementType::COLORLESS,"COLORLESS"},
	{ElementType::FIRE,"FIRE"},
	{ElementType::GRASS,"GRASS"},
	{ElementType::WATER,"WATER"},
	{ElementType::LIGHTNING,"LIGHTNING"},
};


using namespace std;

/// <summary>
/// Pokemon
/// </summary>
class Pokemon {
private:
	int hitPoints;
	int maxHP;
	std::string name;
public:
	Pokemon(std::string name, int maxHP) {
		setName(name);
		setMaxHP(maxHP);
		setHitPoints(0);
	}

	std::string getName() { return name; }
	void setName(std::string s) {
		this->name = s;
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

	virtual Element* getElement() = 0;
};

