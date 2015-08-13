#include <iostream>
#include "Arena.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"
#include "Battle.h"

using namespace std;

int main()
{
	Archer* archer1 = new Archer("Sheep", 5, 1, 1, 1);
	Robot* robot1 = new Robot("Cow", 10, 2, 1, 3);
	fight(archer1, robot1, true);

	system("pause");
	return 0;
}