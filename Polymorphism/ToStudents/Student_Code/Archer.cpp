#include "Archer.h"

Archer::Archer(string name, int hp, int strength, int speed, int magic) : Fighter(name, hp, strength, speed, magic)
{
    start_speed = speed;
}

Archer::~Archer(void) {};
int Archer::getDamage()
{
    return speedSaved;
}
void Archer::reset()
{
    currenthp = maxhp;
    speedSaved = start_speed;
}
bool Archer::useAbility()
{
    speedSaved+=1;
    return true;
}
bool Archer::isSimplified()
{
    return false;
}
