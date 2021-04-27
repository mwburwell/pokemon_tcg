/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#pragma once
#include <iostream>
#include <string>
#include "Enumerators.h"

class Element {
protected:
	int weaknessMultiplier;
	int resistanceMultiplier;
	ElementType weaknessType;
	ElementType resistanceType;
	ElementType attackType;
public:
	Element(ElementType attackType, ElementType weak, ElementType resistant, bool flyingType = false) {
		this->attackType = attackType;
		this->weaknessType = weak;
		if (flyingType) {
			this->resistanceType = ElementType::FIGHTING;
		}
		else {
			this->resistanceType = resistant;
		}
		this->weaknessMultiplier = 2;		// Pokemon Takes 2 times the damage if weak against attack 
		this->resistanceMultiplier = 20;	// Pokemon takes 20 less damage if resistance to attack
	}


	int getWeaknessMultiplier() { return this->weaknessMultiplier; }
	int getResistanceMultiplier() { return this->resistanceMultiplier; }
	ElementType getWeaknessType() { return this->weaknessType; }
	ElementType getResistanceType() { return this->resistanceType; }
	ElementType getAttackType() { return this->attackType; }
	// virtual int getWeaknessMultiplier() = 0;
	// virtual int getResistanceMultiplier() = 0;
	// virtual Element getWeaknessType() = 0;
	// virtual Element getResistanceType() = 0;
	// virtual Element getAttackType() = 0;
};



/*******************************************************************************************
 Fire Type Pokemon
 Usual Weakness:  WATER
 Resistance: NONE
 ******************************************************************************************/
class Fire : public Element {
public:
	Fire()
		: Element(ElementType::FIRE, ElementType::WATER, ElementType::NONE) {}

	Fire(ElementType weak)
		: Element(ElementType::FIRE, weak, ElementType::NONE) {}

	Fire(bool canFly)
		: Element(ElementType::FIRE, ElementType::WATER, ElementType::NONE, canFly) {}

	Fire(ElementType weak, bool canFly)
		: Element(ElementType::FIRE, weak, ElementType::NONE, canFly) {}

	Fire(ElementType weak, ElementType resist)
		: Element(ElementType::FIRE, weak, resist) {}
};



/*******************************************************************************************
 Water Type Pokemon
 Usual Weakness:  Lightning
 Resistance: NONE
 ******************************************************************************************/
class Water : public Element {
public:
	Water()
		: Element(ElementType::WATER, ElementType::LIGHTNING, ElementType::NONE) {}

	Water(ElementType weak)
		: Element(ElementType::WATER, weak, ElementType::NONE) {}

	Water(bool canFly)
		: Element(ElementType::WATER, ElementType::LIGHTNING, ElementType::NONE, canFly) {}

	Water(ElementType weak, bool canFly)
		: Element(ElementType::WATER, weak, ElementType::NONE, canFly) {}

	Water(ElementType weak, ElementType resist)
		: Element(ElementType::WATER, weak, resist) {}
};



/*******************************************************************************************
 Fighting Type Pokemon
 Usual Weakness:  {GRASS, PSYCHIC, WATER}
 Resistance: NONE
 ******************************************************************************************/
class Fighting : public Element {
public:
	/* Fightin Pokemon can not fly, hence why no canfly constructor */
	Fighting(ElementType weak)
		: Element(ElementType::FIGHTING, weak, ElementType::NONE) {}

	Fighting(ElementType weak, ElementType resist)
		: Element(ElementType::FIGHTING, weak, resist) {}
};



/*******************************************************************************************
 PSYCHIC Type Pokemon
 Usual Weakness:  PSYCHIC
 Resistance: NONE
 ******************************************************************************************/
class Psychic : public Element {
public:
	Psychic()
		: Element(ElementType::PSYCHIC, ElementType::PSYCHIC, ElementType::NONE) {}

	Psychic(ElementType weak)
		: Element(ElementType::PSYCHIC, weak, ElementType::NONE) {}

	Psychic(bool canFly)
		: Element(ElementType::PSYCHIC, ElementType::PSYCHIC, ElementType::NONE, canFly) {}

	Psychic(ElementType weak, bool canFly)
		: Element(ElementType::PSYCHIC, weak, ElementType::NONE, canFly) {}

	Psychic(ElementType weak, ElementType resist)
		: Element(ElementType::PSYCHIC, weak, resist) {}
};



/*******************************************************************************************
 DARKNESS Type Pokemon
 Usual Weakness:  FIGHTING
 Resistance: PSYCHIC
 ******************************************************************************************/
class Darkness : public Element {
public:
	Darkness()
		: Element(ElementType::DARKNESS, ElementType::FIGHTING, ElementType::PSYCHIC) {}

	Darkness(ElementType weak)
		: Element(ElementType::DARKNESS, weak, ElementType::PSYCHIC) {}

	Darkness(bool canFly)
		: Element(ElementType::DARKNESS, ElementType::FIGHTING, ElementType::PSYCHIC, canFly) {}

	Darkness(ElementType weak, ElementType resist)
		: Element(ElementType::DARKNESS, weak, resist) {}

	Darkness(ElementType weak, bool canFly)
		: Element(ElementType::DARKNESS, weak, ElementType::PSYCHIC, canFly) {}
};



/*******************************************************************************************
 METAL Type Pokemon
 Usual Weakness:  FIRE
 Resistance: WATER
 ******************************************************************************************/
class Metal : public Element {
public:
	Metal()
		: Element(ElementType::METAL, ElementType::FIRE, ElementType::WATER) {}

	Metal(ElementType weak)
		: Element(ElementType::METAL, weak, ElementType::WATER) {}

	Metal(bool canFly)
		: Element(ElementType::METAL, ElementType::FIRE, ElementType::WATER, canFly) {}

	Metal(ElementType weak, ElementType resist)
		: Element(ElementType::METAL, weak, resist) {}

	Metal(ElementType weak, bool canFly)
		: Element(ElementType::METAL, weak, ElementType::WATER, canFly) {}
};



/*******************************************************************************************
 GRASS Type Pokemon
 Usual Weakness:  FIRE
 Resistance: WATER
 ******************************************************************************************/
class Grass : public Element {
public:
	Grass()
		: Element(ElementType::GRASS, ElementType::FIRE, ElementType::WATER) {}

	Grass(ElementType weak)
		: Element(ElementType::GRASS, weak, ElementType::WATER) {}

	Grass(bool canFly)
		: Element(ElementType::GRASS, ElementType::FIRE, ElementType::WATER, canFly) {}

	Grass(ElementType weak, bool canFly)
		: Element(ElementType::GRASS, weak, ElementType::WATER, canFly) {}

	Grass(ElementType weak, ElementType resist)
		: Element(ElementType::GRASS, weak, resist) {}
};



/*******************************************************************************************
 LIGHTNING Type Pokemon
 Usual Weakness:  FIGHTING
 Resistance: NONE
 ******************************************************************************************/
class Lightning : public Element {
public:
	Lightning()
		: Element(ElementType::LIGHTNING, ElementType::FIGHTING, ElementType::NONE) {}

	Lightning(ElementType weak)
		: Element(ElementType::LIGHTNING, weak, ElementType::NONE) {}

	Lightning(bool canFly)
		: Element(ElementType::LIGHTNING, ElementType::FIGHTING, ElementType::NONE, canFly) {}

	Lightning(ElementType weak, bool canFly)
		: Element(ElementType::LIGHTNING, weak, ElementType::NONE, canFly) {}

	Lightning(ElementType weak, ElementType resist)
		: Element(ElementType::LIGHTNING, weak, resist) {}
};

/*******************************************************************************************
 COLORLESS Type Pokemon
 Usual Weakness:  {FIGHTING, LIGHTNING, NONE}
 Resistance: NONE
 ******************************************************************************************/
class Colorless : public Element {
public:
	Colorless(ElementType weak)
		: Element(ElementType::COLORLESS, weak, ElementType::NONE) {}
	Colorless(ElementType weak, bool canFly)
		: Element(ElementType::COLORLESS, weak, ElementType::NONE, canFly) {}
	Colorless(ElementType weak, ElementType resist)
		: Element(ElementType::COLORLESS, weak, resist) {}
};

/*******************************************************************************************
 DRAGON Type Pokemon
 Usual Weakness:  {FAIRY, DRAGON}
 Resistance: NONE
 ******************************************************************************************/
class Dragon : public Element {
public:
	Dragon(ElementType weak)
		: Element(ElementType::DRAGON, weak, ElementType::NONE) {}
	Dragon(ElementType weak, bool canFly)
		: Element(ElementType::DRAGON, weak, ElementType::NONE, canFly) {}
	Dragon(ElementType weak, ElementType resist)
		: Element(ElementType::DRAGON, weak, resist) {}
};

/*******************************************************************************************
 FAIRY Type Pokemon
 Usual Weakness:  METAL
 Resistance: DARKNESS
 ******************************************************************************************/
class Fairy : public Element {
public:
	Fairy()
		: Element(ElementType::FAIRY, ElementType::METAL, ElementType::DARKNESS) {}

	Fairy(ElementType weak)
		: Element(ElementType::FAIRY, weak, ElementType::DARKNESS) {}

	Fairy(bool canFly)
		: Element(ElementType::FAIRY, ElementType::METAL, ElementType::DARKNESS, canFly) {}

	Fairy(ElementType weak, bool canFly)
		: Element(ElementType::FAIRY, weak, ElementType::DARKNESS, canFly) {}

	Fairy(ElementType weak, ElementType resist)
		: Element(ElementType::FAIRY, weak, resist) {}
};
