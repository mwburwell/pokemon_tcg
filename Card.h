/***************************************************************************************************************************
 Class:  CSCI201-0CC-C1-202030-VI-16R
 Program: Pokemon The Card Game
 Instructor:  Kristopher Roberts
 Auther:  Michael Burwell
 Date:  04/10/2021
****************************************************************************************************************************/
/****************************************************************************************************************************
/////////////////////									CARD CLASS		 								/////////////////////
****************************************************************************************************************************/
#pragma once
#include <string>

class Card {
protected:
	bool isDiscarded;
	bool isPrizeCard;
	bool isOnBench;
	std::string name;
	CardType cardType;
public:
	Card(std::string name, CardType type) {
		setName(name);
		this->cardType = type;
	}
	~Card() {

	}

	std::string getName() {
		return this->name;
	}
	void setName(std::string name) {
		this->name = name;
	}

	void Discard() {
		this->isDiscarded = true;
	}

};

