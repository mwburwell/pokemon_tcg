# Add Pokemon:

To add a Pokémon go to the Derived Pokémon file and Add your Pokémon here.

*Here is an example of a Squirtle:*

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
			delet element;
			bubble = NULL;
			waterGun = NULL;
			element = NULL;
		}

		Attack* Attack1() { return this->bubble; }
		Attack* Attack2() { return this->waterGun; }
		Attack* Attack3() { return NULL; }
		Element* getElement() { return this->element;}
	};




## Pokémon Base classes: 

The DerivedPokémon can inherit Either a **Basic, Stage_1, or Stage_2** Pokémon.  The constructors for these three types of Pokémon all have the same constructor and take four parameters:

BASIC, STAGE_1, STAGE_2 parameters in order:

	int cardIDNumber	- is the Pokémon card's ID number.  This can be used to check if a Stage_1 or Stage_2 evolution Pokémon can evolve from this Pokémon.
	string name		- is the name of the Pokemon
	int maxHP		- is the Pokémon's maximum hit points allowed before it falls.
	int retreatCost		- is the amount of energy cards that will need to be paid to allow the Pokémon to retreat.

*Squirtle:*

	Squirtle() : Basic(7, "Squirtle", 50, 1)
	cardIDNumber 	-> 7
	name		-> Squirtle
	maxHP		-> 50
	retreatCost	-> 1
	
*Wartortle*

	Wartortle() : Stage_1(8, "Wartortle", 80, 2)
	cardIDNumber 	-> 8
	name		-> Wartortle
	maxHP		-> 80
	retreatCost	-> 2
	
*Blastoise*

	Blastoise() : Stage_2(9, "Blastoise", 180, 3)
	cardIDNumber 	-> 9
	name		-> Blastoise
	maxHP		-> 180
	retreatCost	-> 3
	
	

## Element Types:

Derived Pokémon have an **Element** as a member.  There are currently 11 types programed **(FIGHTING, PSYCHIC, DARKNESS, METAL, COLORLESS, FIRE, GRASS, WATER, LIGHTNING, DRAGON, FAIRY)**.

Each element inherits from the Elemental Type Constructor and adds it's attack element with the weakness and resistance types.

Elemental Type constructor:

	ElementalType(Element attackType, Element weak, Element resistant, bool flyingType = false)


Each type has multiple constructors allowing flexibility in creating different elemental type weaknesses and resistances.   

*Using Water for an Example:*

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

## How to add an element to the pokemon

Here is an example of a element added to squirtle:

	class Squirtle : virtual public Basic{
	private:
		Element* element;
	public:
		/// <param name = "None"> No parameters </param>
		Squirtle() : 
		Basic(7, "Squirtle", 50, 1) {
			this->element = new Water();
		}
		~Squirtle() {
			delete element;
			element = NULL;
		}

		Element* getElement() { return this->element;}
	};
	
Add the element as an attribute:

	Element* element;
Initialize the element in the constructor with you Pokémon's element:

	Squirtle() : 
	Basic(7, "Squirtle", 50, 1) {
		this->element = new Water();
	}
	
If you want to specify a specific Weakness add it into the child Element constructor:

	this->element = new Water(ElementType::GRASS);	// water attack type, weakness to GRASS, resistance to none

More constructor examples:

	this->element = new Water(ElementType::GRASS, ElementType::FIRE);	// water attack type, weakness to GRASS, resistance to FIRE
	this->element = new Water(ElementType::GRASS, true);	// water attack type, weakness to GRASS, resistance to FIGHTING because flying Pokemon are resistant to FIGHTING
	this->element = new Water(true);	// water attack type, weakness to LIGHTNING, resistance to FIGHTING



Delete the element and set it's pointer to null once the Pokémon has been destroyed:

	~Squirtle() {
		delete element;
		element = NULL;
	}
Finally write a getter for the element.  This is a virtual function and needs to be implemented in order to derive a Pokémon.

	Element* getElement() { return this->element;}


Some of the Element Types do not have all of the same constructors as the **Water** element.  Some elemental types do not specify a default constructor because they do not have a default weakness.  Some Pokémon can not fly, i.e. FIGHTING Pokémon.

Look up your Pokémon's Elemental Type to see the Constructors available for the Pokémon.


## Adding Attacks To Pokémon:
I recomend before adding an attack to a Pokémon go and add the attack to the attack file.  // TODO add an attack file example

An attack will be a member of the Derived Pokémon class and also will be implemented in a get **Attack** function.  There are three virtual functions that need to be implemented for each Pokémon.

	Attack* Attack1()
	Attack* Attack2()
	Attack* Attack3()

These functions will return a pointer to the attack member declared in your Pokémon class.  I included three just in case.  Most of the Time the third function will retrun a *Null* pointer.

*Using Squirtle again*

	class Squirtle : virtual public Basic, public Water {
	private:
		Attack* bubble;
	public:
		Squirtle() : Basic(7, "Squirtle", 50, 1), Water() {
			this->bubble = new Bubble(0, 1, 0);
		}
		~Squirtle() {
			delete bubble;
			bubble = NULL;
		}

		Attack* Attack1() { return this->bubble; }
		Attack* Attack2() { return NULL; }
		Attack* Attack3() { return NULL; }
	};
	
Declare the Attack pointer as a member variable:

	Attack* bubble;

And in the constructor create a new attack with the Attack that you coded in the Attack File:
	
	this->bubble = new Bubble(0, 1, 0);
	
I would make sure to delete the Attack in the Destructor of the class and set the pointer to null: 

	~Squirtle(){
		delete bubble;
		bubble = NULL;
	}
	
Now that we have an attack we can call it using the virtual Attack1() function by returning the attack:

	Attack* Attack1() { return this->bubble; }
