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
	/// <summary>
	/// Attack Base Class
	/// </summary>
	/// <param name = "attackName"> - The name of the Attack</param>
	/// <param name = "desc"> - The description of the Attack</param>
	/// <param name = "hitPoints"> - Number of hitpoints the Attack causes</param>
	/// <param name = "elementCost"> - Required number of Elemental specific energy cards that need to be attached to the pokemon to use this Attack</param>
	/// <param name = "colorlessCost"> - Required number of additional energy cards of ANY type that need to be attached to the pokemon to use this Attack</param>
	/// <param name = "attackElement"> - The element type of the Attack</param>
	Attack(std::string attackName, std::string desc, int hitpoints, int elCost, int coCost, Element attackElement) {
		this->attackName = attackName;
		this->hitpoints = hitpoints;
		this->attackElement = attackElement;
		this->description = desc;
		this->elementTypeCost = elCost;
		this->colorlessTypeCost = coCost;
	}
	/// <summary>
	/// Attack Base Class
	/// </summary>
	/// <param name = "attackName"> - The name of the Attack</param>
	/// <param name = "desc"> - The description of the Attack</param>
	/// <param name = "hitPoints"> - Number of hitpoints the Attack causes</param>
	/// <param name = "elementCost"> - Required number of Elemental specific energy cards that need to be attached to the pokemon to use this Attack</param>
	/// <param name = "colorlessCost"> - Required number of additional energy cards of ANY type that need to be attached to the pokemon to use this Attack</param>
	/// <param name = "attackElement"> - The element type of the Attack</param>
	/// <param name = "statusEffect"> - The StatusEffect caused by the attack</param>
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


class Bubble : public Attack {
public:
	/// <summary>
	/// Bubble - derived class of Attack 
	/// </summary>
	/// <param name = "hitPoints"> - Number of hitpoints the Attack causes</param>
	/// <param name = "elementCost"> - Required number of Elemental specific energy cards that need to be attached to the pokemon to use this Attack</param>
	/// <param name = "colorlessCost"> - Required number of additional energy cards of ANY type that need to be attached to the pokemon to use this Attack</param>
	Bubble(int hitPoints, int elementCost, int colorlessCost) :
		Attack("Bubble", "Flip a coin, if heads the defending Pokemon is now paralyzed",
			hitPoints, elementCost, colorlessCost, Element::WATER, StatusEffects::PARALYSIS) {
	}
};

class WaterGun : public Attack {
public:
	/// <summary>
	/// WaterGun - derived class of Attack
	/// </summary>
	/// <param name = "hitPoints"> - Number of hitpoints the Attack causes</param>
	/// <param name = "elementCost"> - Required number of Elemental specific energy cards that need to be attached to the pokemon to use this Attack</param>
	/// <param name = "colorlessCost"> - Required number of additional energy cards of ANY type that need to be attached to the pokemon to use this Attack</param>
	WaterGun(int hitPoints, int elementCost, int colorlessCost) :
		Attack("Water Gun", "Shoots Water Gun",
			hitPoints, elementCost, colorlessCost, Element::WATER) {}
};