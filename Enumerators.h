/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#pragma once
#include <map>
#include <vector>
#include <string>
#include <cstdint>

 /* Enumerations and string maps for Pokemon Card Types */
enum class PokemonCardType { BASIC, STAGE_1, STAGE_2 };
std::map<PokemonCardType, std::string> pokemonCardTypeNames = {
	{PokemonCardType::BASIC, "BASIC"},
	{PokemonCardType::STAGE_1,"EVOLUTION"},
	{PokemonCardType::STAGE_2,"SPECIAL"}
};

/* Enumerations and string maps for Element Types */
enum class ElementType { FIGHTING, PSYCHIC, DARKNESS, METAL, COLORLESS, FIRE, GRASS, WATER, LIGHTNING, DRAGON, FAIRY, NONE };
std::map<ElementType, std::string> elementTypeNames = {
	{ElementType::FIGHTING,"FIGHTING"},
	{ElementType::PSYCHIC, "PSYCHIC"},
	{ElementType::DARKNESS, "DARKNESS"},
	{ElementType::METAL,"METAL"},
	{ElementType::COLORLESS,"COLORLESS"},
	{ElementType::FIRE,"FIRE"},
	{ElementType::GRASS,"GRASS"},
	{ElementType::WATER,"WATER"},
	{ElementType::LIGHTNING,"LIGHTNING"},
	{ElementType::DRAGON,"DRAGON"},
	{ElementType::FAIRY,"FAIRY"},
	{ElementType::NONE,"NONE"}
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

// enum class AllPokemon {SQUIRTLE, BLASTOISE, WARTORTLE, EEVEE};
// std::vector<int> ints;
// const std::map<ElementType, std::vector<AllPokemon> > allPokemonNames = {
// 	{ElementType::WATER, {
// 		AllPokemon::SQUIRTLE, 
// 		AllPokemon::WARTORTLE, 
// 		AllPokemon::BLASTOISE
// 		} 
// 	},

// 	{ElementType::COLORLESS, {
// 		AllPokemon::EEVEE
// 		} 
// 	}
// };