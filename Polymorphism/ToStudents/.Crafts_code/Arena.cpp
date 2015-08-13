#include "Arena.h"
#include "Cleric.h"
#include "Robot.h"
#include "Archer.h"
#include <sstream>
#include <vector>

Arena::Arena(void) {}
Arena::~Arena(void) {}

bool addFighter(string stats)
{
    istringstream stream(stats);
    string name;
    stream >> name;

    for (int i=0; i<Fighters.size(); i++)
    {
        if (Fighters[i]->getName() == name)
        {
            return false;
        }
    }
    string RAC;
    stream >> RAC;
    int hp;
    stream >> hp;
    int strength;
    stream >> strength;
    int speed;
    stream >> speed;
    int magic;
    stream >> magic;
    if (hp<=0||strength<=0||magic<=0||speed<=0||(RAC!="A"&&RAC!="C"&&RAC!="R"))
    {
        return false;
    }
    if (RAC=="R")
    {
        Fighters.push_back(new Robot(name, hp, strength, speed, magic));
    }
    else if (RAC=="A")
    {
        Fighters.push_back(new Archer(name, hp, strength, speed, magic));
    }
    else if (RAC=="C")
    {
        Fighters.push_back(new Cleric(name, hp, strength, speed, magic));
    }
    return true;
}

bool removeFighter(string name)
{
    for (int i=0; i<Fighters.size(); i++)
    {
        if (Fighters[i]->getName() == name)
        {
            delete Fighters[i];
            int num = Fighters.size()-1;
            Fighters[i]=Fighters[num];
            Fighters.pop_back();
            return true;
        }
    }
    return false;
}

FighterInterface *getFighter(string name)
{
    for (int i=0; i<Fighters.size(); i++)
    {
        if (Fighters[i]->getName() == name)
        {
            return Fighters[i];
        }
    }
    return NULL;
}

int getSize()
{
    return Fighters.size();
}
