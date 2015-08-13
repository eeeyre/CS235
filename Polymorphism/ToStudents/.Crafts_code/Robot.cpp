#include "Robot.h"
#include <cmath>
Robot::Robot(string name, int hp, int strength, int speed, int magic):Fighter(name, hp, strength, speed, magic)
{
    bonus_damage=0;
    max_energy=2*magic;
    current_energy=max_energy;
}
Robot::~Robot(void) {}
int Robot::getDamage()
{
    int damage=strengthSaved+bonus_damage;
    bonus_damage=0;
    return damage;
}
bool Robot::useAbility()
{
    if (current_energy>=ROBOT_ABILITY_COST)
    {
        double abilityEnergy=current_energy;
        double MaxAbilityEnergy=max_energy;
        double AbilityStrength=strengthSaved;
        double AbilityBonus=(AbilityStrength*(pow((abilityEnergy/MaxAbilityEnergy), 4)));
        bonus_damage=AbilityBonus;
        current_energy-=ROBOT_ABILITY_COST;
        return true;
    }
    return false;
}
bool Robot::isSimplified()
{
    return false;
}
void Robot::reset()
{
    currenthp=maxhp;
    current_energy=2*magicSaved;
    bonus_damage=0;
}
