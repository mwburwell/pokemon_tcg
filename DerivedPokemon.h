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
class Squirtle : virtual public Basic, public Water {
private:
	Attack* bubble;
	Attack* waterGun;
public:
	/// <param name = "None"> No parameters </param>
	Squirtle() : Basic(7, "Squirtle", 50, 1), Water() {
		this->bubble = new Bubble(0, 1, 0);
		this->waterGun = new WaterGun(20, 1, 1);
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
class Wartortle : virtual public Stage_1, public Water {
private:
	Attack* bubble;
	Attack* surf;
	int cardIDEvolvedFrom;
public:
	Wartortle() : Stage_1(8, "Wartortle", 80, 2), Water() {
		this->cardIDEvolvedFrom = 7;			// evolves from squirtle whose ID number is 7
		this->bubble = new Bubble(20, 1, 1);
		this->surf = new Surf(50, 1, 2);
	}
	~Wartortle() {
		delete bubble;
		delete surf;
		bubble = NULL;
		surf = NULL;
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
class Blastoise : virtual public Stage_2, public Water {
private:
	Attack* attack1;
	Attack* attack2;
	int cardIDEvolvedFrom;
public:
	Blastoise() : Stage_2(9, "Blastoise", 180, 3), Water() {
		this->cardIDEvolvedFrom = 8;			// evolves from Wartotle whose ID number is 8
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
	Eevee() : Basic(133, "Eevee", 80, 1), Colorless(Element::FIGHTING) {
	}
	~Eevee() {
	}

	Attack* Attack1() { return NULL; }
	Attack* Attack2() { return NULL; }
	Attack* Attack3() { return NULL; }
};
