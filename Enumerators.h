/***************************************************************************************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 ***************************************************************************************************************************/
 /****************************************************************************************************************************
 /////////////////////							Enumerations Being Used 								/////////////////////
 ****************************************************************************************************************************/
#pragma once
#include <map>
#include <string>

 /* Enumerations and string maps for Pokemon Card Types */
enum class PokemonCardType { BASIC, STAGE_1, STAGE_2 };
std::map<PokemonCardType, std::string> pokeCardTypeNames = {
	{PokemonCardType::BASIC, "BASIC"},
	{PokemonCardType::STAGE_1,"EVOLUTION"},
	{PokemonCardType::STAGE_2,"SPECIAL"}
};

/* Enumerations and string maps for Element Types */
enum class Element { FIGHTING, PSYCHIC, DARKNESS, METAL, COLORLESS, FIRE, GRASS, WATER, LIGHTNING, DRAGON, FAIRY, NONE };
std::map<Element, std::string> elementNames = {
	{Element::FIGHTING,"FIGHTING"},
	{Element::PSYCHIC, "PSYCHIC"},
	{Element::DARKNESS, "DARKNESS"},
	{Element::METAL,"METAL"},
	{Element::COLORLESS,"COLORLESS"},
	{Element::FIRE,"FIRE"},
	{Element::GRASS,"GRASS"},
	{Element::WATER,"WATER"},
	{Element::LIGHTNING,"LIGHTNING"},
	{Element::DRAGON,"DRAGON"},
	{Element::FAIRY,"FAIRY"},
	{Element::NONE,"NONE"}
};

/* Enumerations and string map for Status Effects */
enum class StatusEffects { PARALYSIS, SLEEP, CONFUSION, BURN, POISON };
std::map<StatusEffects, std::string> statusEffectNames = {
	{StatusEffects::PARALYSIS, "PARALYSIS"},
	{StatusEffects::SLEEP, "SLEEP"},
	{StatusEffects::CONFUSION, "CONFUSION"},
	{StatusEffects::BURN, "BURN"},
	{StatusEffects::POISON,"POISON"}
};

/* Enumerations and string map for the Card Types */
enum class CardType { POKEMON, ENERGY, TRAINER };
std::map<CardType, std::string> cardTypeNames = {
	{CardType::POKEMON, "POKEMON"},
	{CardType::ENERGY, "ENERGY"},
	{CardType::TRAINER, "TRAINER"}
};