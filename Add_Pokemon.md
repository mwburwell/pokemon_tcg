# Add Pokemon:

To add a Pokémon go to the Derived Pokémon file and Add your Pokémon here.

## Pokémon Base classes: 

The DerivedPokémon can inherit Either a **Basic, Stage_1, or Stage_2** Pokémon.  The constructors for these three types of Pokémon all have the same constructor and take four parameters:

BASIC, STAGE_1, STAGE_2 parameters in order:

	int cardIDNumber	- is the Pokémon card's ID number.  This can be used to check if a Stage_1 or Stage_2 evolution Pokémon can evolve from this Pokémon.
	string name		- is the name of the Pokemon
	int maxHP		- is the Pokémon's maximum hit points allowed before it falls.
	int retreatCost		- is the amount of energy cards that will need to be paid to allow the Pokémon to retreat.

*Example:*

	Squirtle() : Basic(7, "Squirtle", 50, 1)
	cardIDNumber 	-> 7
	name		-> Squirtle
	maxHP		-> 50
	retreatCost	-> 1


## Element Types:

Derived Pokémon should also inherit an elemental Type.  There are currently 11 types programed **(FIGHTING, PSYCHIC, DARKNESS, METAL, COLORLESS, FIRE, GRASS, WATER, LIGHTNING, DRAGON, FAIRY)**.

Each type has multiple constructors allowing flexibility in creating different elemental type weaknesses and resistances.  Some more than others.  Using Water for an 

*Example:*

	Water()		// default constructor Water, Weak to lightning, no resistance
		: ElementalType(Element::WATER, Element::LIGHTNING, Element::NONE) {}

	Water(Element weak)	// modify weakness constructor allows to change weakness, not resistance
		: ElementalType(Element::WATER, weak, Element::NONE) {}

	Water(bool canFly)	// modify's resistance to FIGHTING
		: ElementalType(Element::WATER, Element::LIGHTNING, Element::NONE, canFly) {}

	Water(Element weak, bool canFly)	// modify weakness and resistance to FIGHTING Pokémon
		: ElementalType(Element::WATER, weak, Element::NONE, canFly) {}

	Water(Element weak, Element resist)	// modify the weakness and the resistance
		: ElementalType(Element::WATER, weak, resist) {}

*How to use the elemental constructors:*


	Squirtle() : Basic(7, "Squirtle", 50, 1), Water() 			// creates a basic water type Pokémon with weakness to LIGHTNING and no resistance
	Squirtle() : Basic(7, "Squirtle", 50, 1), Water(Element::GRASS) 	// creates a water type Pokémon with weakness to GRASS and no resistance
	Squirtle() : Basic(7, "Squirtle", 50, 1), Water(true) 			// creates a water type Flying Pokémon that is weak to LIGHTNING and resistant to FIGHTING
	Squirtle() : Basic(7, "Squirtle", 50, 1), Water(Element::GRASS, true) 	// creates a water type Pokémon with weakness to GRASS and resistant to FIGHTING
	Squirtle() : Basic(7, "Squirtle", 50, 1), Water(Element::GRASS, Element::FIRE) // creates a water type Pokémon with weakness to GRASS and resistant to FIRE


