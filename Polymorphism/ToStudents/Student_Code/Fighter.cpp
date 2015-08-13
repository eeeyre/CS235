#include "Fighter.h"
Fighter::Fighter(string name, int hp, int strength, int speed, int magic)
{
    nameSaved = name;
    maxhp = hp;
    strengthSaved = strength;
    speedSaved = speed;
    currenthp = hp;
    magicSaved = magic;
}
Fighter::~Fighter(void) {}
string Fighter::getName()
{
    return nameSaved;
}
int Fighter::getMaximumHP()
{
    return maxhp;
}
int Fighter::getCurrentHP()
{
    return currenthp;
}
int Fighter::getStrength()
{
    return strengthSaved;
}
int Fighter::getMagic()
{
    return magicSaved;
}
int Fighter::getSpeed()
{
    return speedSaved;
}
void Fighter::takeDamage(int damage)
{
    int dmg_received = damage - (speedSaved/4);
     if (dmg_received<1)
    {
        currenthp-=1;
    }
    else
    {
    currenthp-=dmg_received;
    }

}
void Fighter::regenerate()
{
    int increase=strengthSaved / 6;
    currenthp+=increase;
    if (increase<1)
    {
        currenthp+=1;
    }
    if (currenthp>maxhp)
    {
        currenthp=maxhp;
    }
}
