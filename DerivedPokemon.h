/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
#include "ElementalType.h"

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
class Squirtle : public Pokemon {
private:
	Element* element;
public:
	/// <param name = "None"> No parameters </param>
	Squirtle() : 
	Pokemon("Squirtle", 50) {
		this->element = new Water();
	}
	~Squirtle() {
		delete element;
		element = NULL;
	}

	Element* getElement() { return this->element;}
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
/// <returns> A Squirtle </returns>j
class Wartortle : public Pokemon {
private:
	int attack;
	string attackName;
	int criticalAttack;
	string criticalAttack;
	Element* element;
public:
	Wartortle() : 
	Pokemon("Wartortle", 80) {
		this->element = new Water();
	}
	~Wartortle() {
		delete element;
		element = NULL;
	}

	Element* getElement() { return this->element;}
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
class Blastoise : public Pokemon {
private:
	int cardIDEvolvedFrom;
	Element* element;
public:
	Blastoise() : 
	Pokemon("Blastoise", 180) {
		this->cardIDEvolvedFrom = 8;			// evolves from Wartotle whose ID number is 8
		this->element = new Water();
	}
	~Blastoise() {
		delete element;
		element = NULL;
	}

	Element* getElement() {return this->element; }
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
class Eevee : public Pokemon {
private:
	Element* element;
public:
	Eevee() : 
	Pokemon("Eevee", 80) {
		element = new Colorless(ElementType::FIGHTING);
	}
	~Eevee() {
		delete element;
		element = NULL;
	}

	Element* getElement() { return this->element;}
};
