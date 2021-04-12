/***************************************************************************************************************************
 Class:  CSCI201-0CC-C1-202030-VI-16R
 Program: Pokemon The Card Game
 Instructor:  Kristopher Roberts
 Auther:  Michael Burwell
 Date:  04/10/2021
****************************************************************************************************************************/
/****************************************************************************************************************************
/////////////////////								Elemental Types		 								/////////////////////
****************************************************************************************************************************/
#pragma once
#include <iostream>
#include <string>
#include "Enumerators.h"

class ElementalType {
protected:
	int weaknessMultiplier;
	int resistanceMultiplier;
	Element weaknessType;
	Element resistanceType;
	Element attackType;
public:
	ElementalType(Element attackType, Element weak, Element resistant) {
		this->attackType = attackType;
		this->weaknessType = weak;
		this->resistanceType = resistant;
		this->weaknessMultiplier = 2;		// Pokemon Takes 2 times the damage if weak against attack 
		this->resistanceMultiplier = 20;	// Pokemon takes 20 less damage if resistance to attack
	}
	
	ElementalType(Element attackType, Element weak, Element resistant, bool flyingType) {
		this->attackType = attackType;
		this->weaknessType = weak;
		if (flyingType) {
			this->resistanceType = Element::FIGHTING;
		}
		else {
			this->resistanceType = resistant;
		}
		this->weaknessMultiplier = 2;		// Pokemon Takes 2 times the damage if weak against attack 
		this->resistanceMultiplier = 20;	// Pokemon takes 20 less damage if resistance to attack
	}

	int getWeaknessMultiplier() { return this->weaknessMultiplier; }
	int getResistanceMultiplier() { return this->resistanceMultiplier; }
	Element getWeaknessType() { return this->weaknessType; }
	Element getResistanceType() { return this->resistanceType; }
	Element getAttackType() { return this->attackType; }
};



/*******************************************************************************************
 * Fire Type Pokemon
 * Usual Weakness:  WATER       Resistance: NONE
 ******************************************************************************************/
class Fire : public ElementalType {
public:
									/* Basic Fire Pokemon Class */
	Fire() :ElementalType(Element::FIRE, Element::WATER, Element::NONE) {}
									/* Determine Fire Pokemon's Weakness */
	Fire(Element weak) : ElementalType(Element::FIRE, weak, Element::NONE) {}
									/* Determine Fire Pokemon's Weakness and Resistance */
	Fire(Element weak, Element resist) :ElementalType(Element::FIRE, weak, resist) {}
									/* If Fire Pokemon can Fly */
	Fire(bool canFly) :ElementalType(Element::FIRE, Element::WATER, Element::NONE, canFly) {}
									/* Determine Weakness for a flying Fire Pokemon */
	Fire(Element weak, bool canFly) : ElementalType(Element::FIRE, weak, Element::NONE, canFly) {}

};



/*******************************************************************************************
 * Water Type Pokemon
 * Usual Weakness:  Lightning       Resistance: NONE
 ******************************************************************************************/
class Water : public ElementalType {
public:
										/* Basic Water Pokemon Class */
	Water() :ElementalType(Element::WATER, Element::LIGHTNING, Element::NONE) {}
										/* Determine water Pokemon's Weakness */
	Water(Element weak) : ElementalType(Element::WATER, weak, Element::NONE) {}
										/* Determine water Pokemon's Weakness and Resistance */
	Water(Element weak, Element resist) :ElementalType(Element::WATER, weak, resist) {}
										/* If water Pokemon can Fly */
	Water(bool canFly) :ElementalType(Element::WATER, Element::LIGHTNING, Element::NONE, canFly) {}
										/* Determine Weakness for a flying water Pokemon */
	Water(Element weak, bool canFly) : ElementalType(Element::WATER, weak, Element::NONE, canFly) {}
};



/*******************************************************************************************
 * Fighting Type Pokemon
 * Usual Weakness:  {GRASS, PSYCHIC, WATER}       Resistance: NONE
 ******************************************************************************************/
class Fighting : public ElementalType {
public:
	/* Determine fighting Pokemon's Weakness */
	Fighting(Element weak) : ElementalType(Element::FIGHTING, weak, Element::NONE) {}
	/* Determine fighting Pokemon's Weakness and Resistance */
	Fighting(Element weak, Element resist) :ElementalType(Element::FIGHTING, weak, resist) {}
};



/*******************************************************************************************
 * PSYCHIC Type Pokemon
 * Usual Weakness:  PSYCHIC       Resistance: NONE
 ******************************************************************************************/
class Psychic : public ElementalType {
public:
										/* Basic Psychic Pokemon Class */
	Psychic() :ElementalType(Element::PSYCHIC, Element::PSYCHIC, Element::NONE) {}
										/* Determine Psychic Pokemon's Weakness */
	Psychic(Element weak) : ElementalType(Element::PSYCHIC, weak, Element::NONE) {}
										/* Determine Psychic Pokemon's Weakness and Resistance */
	Psychic(Element weak, Element resist) :ElementalType(Element::PSYCHIC, weak, resist) {}
										/* If Psychic Pokemon can Fly */
	Psychic(bool canFly) :ElementalType(Element::PSYCHIC, Element::PSYCHIC, Element::NONE, canFly) {}
										/* Determine Weakness for a flying psychic Pokemon */
	Psychic(Element weak, bool canFly) : ElementalType(Element::PSYCHIC, weak, Element::NONE, canFly) {}
};



/*******************************************************************************************
 * DARKNESS Type Pokemon
 * Usual Weakness:  FIGHTING       Resistance: PSYCHIC
 ******************************************************************************************/
class Darkness : public ElementalType {
public:
										/* Basic darkness Pokemon Class */
	Darkness() :ElementalType(Element::DARKNESS, Element::FIGHTING, Element::PSYCHIC) {}
										/* Determine darkness Pokemon's Weakness */
	Darkness(Element weak) : ElementalType(Element::DARKNESS, weak, Element::PSYCHIC) {}
										/* Determine darkness Pokemon's Weakness and Resistance */
	Darkness(Element weak, Element resist) :ElementalType(Element::DARKNESS, weak, resist) {}
										/* If darkness Pokemon can Fly */
	Darkness(bool canFly) :ElementalType(Element::DARKNESS, Element::FIGHTING, Element::PSYCHIC, canFly) {}
										/* Determine Weakness for a flying darkness Pokemon */
	Darkness(Element weak, bool canFly) : ElementalType(Element::DARKNESS, weak, Element::PSYCHIC, canFly) {}
};



/*******************************************************************************************
 * METAL Type Pokemon
 * Usual Weakness:  FIRE       Resistance: WATER
 ******************************************************************************************/
class Metal : public ElementalType {
public:
										/* BasicMetale Pokemon Class */
	Metal() :ElementalType(Element::METAL, Element::FIRE, Element::WATER) {}
										/* Determine Metal Pokemon's Weakness */
	Metal(Element weak) : ElementalType(Element::METAL, weak, Element::WATER) {}
										/* Determine Metal Pokemon's Weakness and Resistance */
	Metal(Element weak, Element resist) :ElementalType(Element::METAL, weak, resist) {}
										/* If Metal Pokemon can Fly */
	Metal(bool canFly) :ElementalType(Element::METAL, Element::FIRE, Element::WATER, canFly) {}
										/* Determine Weakness for a flying Metal Pokemon */
	Metal(Element weak, bool canFly) : ElementalType(Element::METAL, weak, Element::WATER, canFly) {}
};



/*******************************************************************************************
 * GRASS Type Pokemon
 * Usual Weakness:  FIRE       Resistance: WATER
 ******************************************************************************************/
class Grass : public ElementalType {
public:
									/* Basic Grass Pokemon Class */
	Grass() :ElementalType(Element::GRASS, Element::FIRE, Element::WATER) {}
									/* Determine Grass Pokemon's Weakness */
	Grass(Element weak) : ElementalType(Element::GRASS, weak, Element::WATER) {}
									/* Determine Grass Pokemon's Weakness and Resistance */
	Grass(Element weak, Element resist) :ElementalType(Element::GRASS, weak, resist) {}
									/* If Grass Pokemon can Fly */
	Grass(bool canFly) :ElementalType(Element::GRASS, Element::FIRE, Element::WATER, canFly) {}
									/* Determine Weakness for a flying Grass Pokemon */
	Grass(Element weak, bool canFly) : ElementalType(Element::GRASS, weak, Element::WATER, canFly) {}
};



/*******************************************************************************************
 * LIGHTNING Type Pokemon
 * Usual Weakness:  FIGHTING       Resistance: NONE
 ******************************************************************************************/
class Lightning : public ElementalType {
public:
									/* Basic Lightning Pokemon Class */
	Lightning() :ElementalType(Element::LIGHTNING, Element::FIGHTING, Element::NONE) {}
									/* Determine Lightning Pokemon's Weakness */
	Lightning(Element weak) : ElementalType(Element::LIGHTNING, weak, Element::NONE) {}
									/* Determine Lightning Pokemon's Weakness and Resistance */
	Lightning(Element weak, Element resist) :ElementalType(Element::LIGHTNING, weak, resist) {}
									/* If Lightning Pokemon can Fly */
	Lightning(bool canFly) :ElementalType(Element::LIGHTNING, Element::FIGHTING, Element::NONE, canFly) {}
									/* Determine Weakness for a flying Lightning Pokemon */
	Lightning(Element weak, bool canFly) : ElementalType(Element::LIGHTNING, weak, Element::NONE, canFly) {}
};

/*******************************************************************************************
 * COLORLESS Type Pokemon
 * Usual Weakness:  {FIGHTING, LIGHTNING, NONE}       Resistance: NONE
 ******************************************************************************************/
class Colorless : public ElementalType {
public:
	/* Determine Colorless Pokemon's Weakness */
	Colorless(Element weak) : ElementalType(Element::COLORLESS, weak, Element::NONE) {}
	/* Determine Colorless Pokemon's Weakness and Resistance */
	Colorless(Element weak, Element resist) :ElementalType(Element::COLORLESS, weak, resist) {}
	/* Determine Weakness for a flying Colorless Pokemon */
	Colorless(Element weak, bool canFly) : ElementalType(Element::COLORLESS, weak, Element::NONE, canFly) {}
};

/*******************************************************************************************
 * DRAGON Type Pokemon
 * Usual Weakness:  {FAIRY, DRAGON}       Resistance: NONE
 ******************************************************************************************/
class Dragon : public ElementalType {
public:
	/* Determine Dragon Pokemon's Weakness */
	Dragon(Element weak) : ElementalType(Element::DRAGON, weak, Element::NONE) {}
	/* Determine Dragon Pokemon's Weakness and Resistance */
	Dragon(Element weak, Element resist) :ElementalType(Element::DRAGON, weak, resist) {}
	/* Determine Weakness for a flying Dragon Pokemon */
	Dragon(Element weak, bool canFly) : ElementalType(Element::DRAGON, weak, Element::NONE, canFly) {}
};

/*******************************************************************************************
 * FAIRY Type Pokemon
 * Usual Weakness:  METAL       Resistance: DARKNESS
 ******************************************************************************************/
class Fairy : public ElementalType {
public:
										/* Basic Fairy Pokemon Class */
	Fairy() :ElementalType(Element::FAIRY, Element::METAL, Element::DARKNESS) {}
										/* Determine Fairy Pokemon's Weakness */
	Fairy(Element weak) : ElementalType(Element::FAIRY, weak, Element::DARKNESS) {}
										/* Determine Fairy Pokemon's Weakness and Resistance */
	Fairy(Element weak, Element resist) :ElementalType(Element::FAIRY, weak, resist) {}
										/* If Fairy Pokemon can Fly */
	Fairy(bool canFly) :ElementalType(Element::FAIRY, Element::METAL, Element::DARKNESS, canFly) {}
										/* Determine Weakness for a flying Fairy Pokemon */
	Fairy(Element weak, bool canFly) : ElementalType(Element::FAIRY, weak, Element::DARKNESS, canFly) {}
};
