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
	ElementalType(Element attackType, Element weak, Element resistant, bool flyingType = false) {
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
	Fire()								: ElementalType(Element::FIRE, Element::WATER, Element::NONE) {}
	Fire(Element weak)					: ElementalType(Element::FIRE, weak, Element::NONE) {}
	Fire(bool canFly)					: ElementalType(Element::FIRE, Element::WATER, Element::NONE, canFly) {}
	Fire(Element weak, bool canFly)		: ElementalType(Element::FIRE, weak, Element::NONE, canFly) {}
	Fire(Element weak, Element resist)	: ElementalType(Element::FIRE, weak, resist) {}
};



/*******************************************************************************************
 * Water Type Pokemon
 * Usual Weakness:  Lightning       Resistance: NONE
 ******************************************************************************************/
class Water : public ElementalType {
public:
	Water()								: ElementalType(Element::WATER, Element::LIGHTNING, Element::NONE) {}
	Water(Element weak)					: ElementalType(Element::WATER, weak, Element::NONE) {}
	Water(bool canFly)					: ElementalType(Element::WATER, Element::LIGHTNING, Element::NONE, canFly) {}
	Water(Element weak, bool canFly)	: ElementalType(Element::WATER, weak, Element::NONE, canFly) {}
	Water(Element weak, Element resist) : ElementalType(Element::WATER, weak, resist) {}
};



/*******************************************************************************************
 * Fighting Type Pokemon
 * Usual Weakness:  {GRASS, PSYCHIC, WATER}       Resistance: NONE
 ******************************************************************************************/
class Fighting : public ElementalType {
public:
	/* Fightin Pokemon can not fly, hence why no canfly constructor */
	Fighting(Element weak)					: ElementalType(Element::FIGHTING, weak, Element::NONE) {}
	Fighting(Element weak, Element resist)	: ElementalType(Element::FIGHTING, weak, resist) {}
};



/*******************************************************************************************
 * PSYCHIC Type Pokemon
 * Usual Weakness:  PSYCHIC       Resistance: NONE
 ******************************************************************************************/
class Psychic : public ElementalType {
public:
	Psychic()								: ElementalType(Element::PSYCHIC, Element::PSYCHIC, Element::NONE) {}
	Psychic(Element weak)					: ElementalType(Element::PSYCHIC, weak, Element::NONE) {}
	Psychic(bool canFly)					: ElementalType(Element::PSYCHIC, Element::PSYCHIC, Element::NONE, canFly) {}
	Psychic(Element weak, bool canFly)		: ElementalType(Element::PSYCHIC, weak, Element::NONE, canFly) {}
	Psychic(Element weak, Element resist) : ElementalType(Element::PSYCHIC, weak, resist) {}
};



/*******************************************************************************************
 * DARKNESS Type Pokemon
 * Usual Weakness:  FIGHTING       Resistance: PSYCHIC
 ******************************************************************************************/
class Darkness : public ElementalType {
public:
	Darkness()								: ElementalType(Element::DARKNESS, Element::FIGHTING, Element::PSYCHIC) {}
	Darkness(Element weak)					: ElementalType(Element::DARKNESS, weak, Element::PSYCHIC) {}
	Darkness(bool canFly)					: ElementalType(Element::DARKNESS, Element::FIGHTING, Element::PSYCHIC, canFly) {}
	Darkness(Element weak, Element resist)	: ElementalType(Element::DARKNESS, weak, resist) {}
	Darkness(Element weak, bool canFly)		: ElementalType(Element::DARKNESS, weak, Element::PSYCHIC, canFly) {}
};



/*******************************************************************************************
 * METAL Type Pokemon
 * Usual Weakness:  FIRE       Resistance: WATER
 ******************************************************************************************/
class Metal : public ElementalType {
public:
	Metal()								: ElementalType(Element::METAL, Element::FIRE, Element::WATER) {}
	Metal(Element weak)					: ElementalType(Element::METAL, weak, Element::WATER) {}
	Metal(bool canFly)					: ElementalType(Element::METAL, Element::FIRE, Element::WATER, canFly) {}
	Metal(Element weak, Element resist) : ElementalType(Element::METAL, weak, resist) {}
	Metal(Element weak, bool canFly)	: ElementalType(Element::METAL, weak, Element::WATER, canFly) {}
};



/*******************************************************************************************
 * GRASS Type Pokemon
 * Usual Weakness:  FIRE       Resistance: WATER
 ******************************************************************************************/
class Grass : public ElementalType {
public:
	Grass()								: ElementalType(Element::GRASS, Element::FIRE, Element::WATER) {}
	Grass(Element weak)					: ElementalType(Element::GRASS, weak, Element::WATER) {}
	Grass(bool canFly)					: ElementalType(Element::GRASS, Element::FIRE, Element::WATER, canFly) {}
	Grass(Element weak, bool canFly)	: ElementalType(Element::GRASS, weak, Element::WATER, canFly) {}
	Grass(Element weak, Element resist) : ElementalType(Element::GRASS, weak, resist) {}
};



/*******************************************************************************************
 * LIGHTNING Type Pokemon
 * Usual Weakness:  FIGHTING       Resistance: NONE
 ******************************************************************************************/
class Lightning : public ElementalType {
public:
	Lightning()								: ElementalType(Element::LIGHTNING, Element::FIGHTING, Element::NONE) {}
	Lightning(Element weak)					: ElementalType(Element::LIGHTNING, weak, Element::NONE) {}
	Lightning(bool canFly)					: ElementalType(Element::LIGHTNING, Element::FIGHTING, Element::NONE, canFly) {}
	Lightning(Element weak, bool canFly)	: ElementalType(Element::LIGHTNING, weak, Element::NONE, canFly) {}
	Lightning(Element weak, Element resist) : ElementalType(Element::LIGHTNING, weak, resist) {}
};

/*******************************************************************************************
 * COLORLESS Type Pokemon
 * Usual Weakness:  {FIGHTING, LIGHTNING, NONE}       Resistance: NONE
 ******************************************************************************************/
class Colorless : public ElementalType {
public:
	Colorless(Element weak)					: ElementalType(Element::COLORLESS, weak, Element::NONE) {}
	Colorless(Element weak, bool canFly)	: ElementalType(Element::COLORLESS, weak, Element::NONE, canFly) {}
	Colorless(Element weak, Element resist) : ElementalType(Element::COLORLESS, weak, resist) {}
};

/*******************************************************************************************
 * DRAGON Type Pokemon
 * Usual Weakness:  {FAIRY, DRAGON}       Resistance: NONE
 ******************************************************************************************/
class Dragon : public ElementalType {
public:
	Dragon(Element weak)				: ElementalType(Element::DRAGON, weak, Element::NONE) {}
	Dragon(Element weak, bool canFly)	: ElementalType(Element::DRAGON, weak, Element::NONE, canFly) {}
	Dragon(Element weak, Element resist) : ElementalType(Element::DRAGON, weak, resist) {}
};

/*******************************************************************************************
 * FAIRY Type Pokemon
 * Usual Weakness:  METAL       Resistance: DARKNESS
 ******************************************************************************************/
class Fairy : public ElementalType {
public:
	Fairy()								: ElementalType(Element::FAIRY, Element::METAL, Element::DARKNESS) {}
	Fairy(Element weak)					: ElementalType(Element::FAIRY, weak, Element::DARKNESS) {}
	Fairy(bool canFly)					: ElementalType(Element::FAIRY, Element::METAL, Element::DARKNESS, canFly) {}
	Fairy(Element weak, bool canFly)	: ElementalType(Element::FAIRY, weak, Element::DARKNESS, canFly) {}
	Fairy(Element weak, Element resist) : ElementalType(Element::FAIRY, weak, resist) {}
};
