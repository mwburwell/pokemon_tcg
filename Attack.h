/***************************************************************************************************************************
 Class:  CSCI201-0CC-C1-202030-VI-16R
 Program: Pokemon The Card Game
 Instructor:  Kristopher Roberts
 Auther:  Michael Burwell
 Date:  04/10/2021
****************************************************************************************************************************/
/****************************************************************************************************************************
/////////////////////								ATTACK CLASS										/////////////////////
****************************************************************************************************************************/
#pragma once
#include "ElementalType.h"


class Attack {
private:
	std::string attackName, description;
	int hitpoints;
	Element attackElement;
	int elementTypeCost;
	int colorlessTypeCost;
	bool causeStatusEffect;
	StatusEffects effect;
public:
	Attack(std::string attackName, std::string desc, int hitpoints, int elCost, int coCost, Element attackElement) {
		this->attackName = attackName;
		this->hitpoints = hitpoints;
		this->attackElement = attackElement;
		this->description = desc;
		this->elementTypeCost = elCost;
		this->colorlessTypeCost = coCost;
	}
	/* Another Constructor to Add status effects to the Attack */
	Attack(std::string attackName, std::string desc, int hitpoints, int elCost, int coCost, Element attackElement, StatusEffects statusEffect) {
		this->attackName = attackName;
		this->hitpoints = hitpoints;
		this->attackElement = attackElement;
		this->description = desc;
		this->elementTypeCost = elCost;
		this->colorlessTypeCost = coCost;
		this->causeStatusEffect = true;
		effect = statusEffect;
	}

	/* get All of the attributes for the attack */
	std::string getAttackName() { return this->attackName; }
	int getHitpoints() { return this->hitpoints; }
	Element getElementAttackType() { return this->attackElement; }
	int getElementTypeCost() { return this->elementTypeCost; }
	int getColorlessTypeCost() { return this->colorlessTypeCost; }
	int getTotalAttackCost() { return this->colorlessTypeCost + this->elementTypeCost; }
	StatusEffects getStatusEffects() { return this->effect; }

};