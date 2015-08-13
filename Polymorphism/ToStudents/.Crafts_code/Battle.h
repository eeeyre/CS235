#include <iostream>
#include <string>
#include <sstream>
#include "FighterInterface.h"
using namespace std;

/*
 *	WARNING: It is expressly forbidden to modify any part of this document, including its name
 */
//=======================================================================================
FighterInterface* fight(FighterInterface*, FighterInterface*, bool);
void takeTurn(FighterInterface*, FighterInterface*, bool);
//=======================================================================================
/*
 *	fight(FighterInterface, FighterInterface, bool)
 *
 *	Runs through the fighting algorithm for the two given fighters.
 *
 *	Each fighter takes a turn using its special ability, attacking, and regenerating. If 
 *	the other fighter's current hit points falls to or drops below 0, then the other 
 *	fighter has lost.  This process repeats until one fighter has fallen or 100 rounds 
 *	have occurred with neither fighter falling.
 *
 *	If the given boolean is true, this function will print a great deal of information 
 *	during the battle.  This can be useful for testing.
 *
 *	Returns the winner of the fight; null if the fight ends in a draw.
 */
FighterInterface* fight(FighterInterface* c1, FighterInterface* c2, bool verbose)
{
	if(verbose)
	{
		cout << "----------" << c1->getName() << " vs " << c2->getName() << "----------" << endl;
	}
	
	c1->reset();
	c2->reset();

	for(int i=0; i<100; i++)
	{
		//C1's turn
		takeTurn(c1, c2, verbose);
		if(c2->getCurrentHP() <= 0)
		{
			if(verbose)
			{
				cout << c1->getName() << " wins! (" << c1->getCurrentHP() << "/" << c1->getMaximumHP() << " HP left)" << endl;
			}
			return c1;
		}
		
		//C2's turn
		takeTurn(c2, c1, verbose);
		if(c1->getCurrentHP() <= 0)
		{
			if(verbose)
			{
				cout << c2->getName() << " wins! (" << c2->getCurrentHP() << "/" << c2->getMaximumHP() << " HP left)" << endl;
			}
			return c2;
		}
	}
	if(verbose)
	{
		cout << "After 100 rounds, neither fighter has fallen.  It's a draw!" << endl;
	}
	return NULL;
}
//=======================================================================================
/*
 *	takeTurn(FighterInterface*, FighterInterface*, bool)
 *
 *	Runs through a single turn for [attacker] attacking [defender].  Each turn consists of
 *	[attacker] trying to use its special ability, attacking [defender], and regenerating.
 */
void takeTurn(FighterInterface* attacker, FighterInterface* defender, bool verbose)
{
	//Header
	if(verbose)
	{
		cout << "It's " << attacker->getName() << "'s turn! (" << attacker->getCurrentHP() << "/" << attacker->getMaximumHP() << " HP)." << endl;
	}

	//Use Ability
	bool ability = attacker->useAbility();
	if(ability  &&  verbose)
	{
		cout << "\t" << attacker->getName() << " uses a special ability!" << endl;
	}

	//Attack
	int damage = attacker->getDamage();
	int before_attack = defender->getCurrentHP();
	defender->takeDamage(damage);
	int after_attack = defender->getCurrentHP();
	if(verbose)
	{
			cout << "\t" << attacker->getName() << " attacks with " << damage << " damage, and " << defender->getName() << " takes " << (before_attack-after_attack) << " damage." << endl;
	}

	//Regenerate
	int before_regen = attacker->getCurrentHP();
	attacker->regenerate();
	int after_regen = attacker->getCurrentHP();
	if(verbose)
	{
		cout << "\t" << attacker->getName() << " regenerates " << (after_regen-before_regen) << " HP." << endl;
	}
}
//=======================================================================================
