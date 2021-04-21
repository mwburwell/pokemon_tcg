/***************************************************************************************************************************
 Class:  CSCI201-0CC-C1-202030-VI-16R
 Program: Pokemon The Card Game
 Instructor:  Kristopher Roberts
 ***************************************************************************************************************************/
 /****************************************************************************************************************************
 /////////////////////									CARD CLASS		 								/////////////////////
 ****************************************************************************************************************************/
#pragma once
#include <string>
#include "Enumerators.h"

class Card {
protected:
	bool isDiscarded;
	bool isPrizeCard;
	bool isOnBench;
	CardType cardType;
public:
	Card(CardType type) {
		this->cardType = type;
		isDiscarded = false;
		isPrizeCard = false;
		isOnBench = false;
	}
	~Card() {

	}

	//virtual std::string getName() = 0;

	void Discard() {
		this->isDiscarded = true;
	}

};

