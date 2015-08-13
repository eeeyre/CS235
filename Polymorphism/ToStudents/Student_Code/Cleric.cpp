#include "Cleric.h"

Cleric::Cleric(string name, int hp, int strength, int speed, int magic):Fighter(name, hp, strength, speed, magic)
{
    max_mana = 5 * magic;
    mana = max_mana;
}
Cleric::~Cleric(void) {}
int Cleric::getDamage()
{
    return magicSaved;
}
void Cleric::regenerate()
{
    Fighter::regenerate();
    if (magicSaved/5<=0)
    {
        mana += 1;
    }
    else
    {
        mana += (magicSaved/5);
    }
}
bool Cleric::useAbility()
{
    if (mana >= CLERIC_ABILITY_COST)
    {
        currenthp+=(magicSaved/3);
        if (currenthp>maxhp)
        {
            currenthp=maxhp;
        }
        mana-=CLERIC_ABILITY_COST;
        return true;
    }
    else
    {
        return false;
    }
}
bool Cleric::isSimplified()
{
    return false;
}

void Cleric::reset()
{
    currenthp=maxhp;
    mana = 5*magicSaved;
}
