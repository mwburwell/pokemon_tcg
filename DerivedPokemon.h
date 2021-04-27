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
#include "Attack.h"
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
class Squirtle : virtual public Basic{
private:
	Attack* bubble;
	Attack* waterGun;
	Element* element;
public:
	/// <param name = "None"> No parameters </param>
	Squirtle() : 
	Basic(7, "Squirtle", 50, 1) {
		this->bubble = new Bubble(0, 1, 0);
		this->waterGun = new WaterGun(20, 1, 1);
		this->element = new Water();
	}
	~Squirtle() {
		delete bubble;
		delete waterGun;
		delete element;
		element = NULL;
		bubble = NULL;
		waterGun = NULL;
	}

	Attack* Attack1() { return this->bubble; }
	Attack* Attack2() { return this->waterGun; }
	Attack* Attack3() { return NULL; }
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
/// <returns> A Squirtle </returns>
class Wartortle : public Stage_1 {
private:
	Attack* bubble;
	Attack* surf;
	Element* element;
	int cardIDEvolvedFrom;
public:
	Wartortle() : 
	Stage_1(8, "Wartortle", 80, 2) {
		this->cardIDEvolvedFrom = 7;			// evolves from squirtle whose ID number is 7
		this->bubble = new Bubble(20, 1, 1);
		this->surf = new Surf(50, 1, 2);
		this->element = new Water();
	}
	~Wartortle() {
		delete bubble;
		delete surf;
		delete element;
		bubble = NULL;
		surf = NULL;
		element = NULL;
	}

	Attack* Attack1() { return this->bubble; }
	Attack* Attack2() { return this->surf; }
	Attack* Attack3() { return NULL; }
	Element* getElement() { return this->element;}
	// int getWeaknessMultiplier() { return this->weaknessMultiplier; }
	// int getResistanceMultiplier() { return this->resistanceMultiplier; }
	// Element getWeaknessType() { return this->weaknessType; }
	// Element getResistanceType() { return this->resistanceType; }
	// Element getAttackType() { return this->attackType; }
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
class Blastoise : virtual public Stage_2 {
private:
	Attack* attack1;
	Attack* attack2;
	int cardIDEvolvedFrom;
	Element* element;
public:
	Blastoise() : 
	Stage_2(9, "Blastoise", 180, 3) {
		this->cardIDEvolvedFrom = 8;			// evolves from Wartotle whose ID number is 8
		this->element = new Water();
	}
	~Blastoise() {
		delete element;
		element = NULL;
	}

	Attack* Attack1() { return NULL; }
	Attack* Attack2() { return NULL; }
	Attack* Attack3() { return NULL; }
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
class Eevee : public Basic {
private:
	Attack* attack1;
	Attack* attack2;
	Element* element;
public:
	Eevee() : 
	Basic(133, "Eevee", 80, 1) {
		element = new Colorless(ElementType::FIGHTING);
	}
	~Eevee() {
		delete element;
		element = NULL;
	}

	Attack* Attack1() { return this->attack1; }
	Attack* Attack2() { return this->attack2; }
	Attack* Attack3() { return NULL; }
	Element* getElement() { return this->element;}
};
