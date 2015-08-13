#pragma once
#include "FighterInterface.h"
#include <vector>
class Fighter : public FighterInterface
{
    protected:
        string nameSaved;
        int maxhp;
        int currenthp;
        int strengthSaved;
        int speedSaved;
        int magicSaved;

    public:
        Fighter(string name, int hp, int strength, int speed, int magic);
        ~Fighter(void);
        string getName();
        int getMaximumHP();
        int getCurrentHP();
        int getStrength();
        int getMagic();
        int getSpeed();
        void takeDamage(int damage);
        virtual int getDamage() = 0;
        virtual void reset() = 0;
        virtual void regenerate();
        virtual bool useAbility() = 0;
        virtual bool isSimplified() = 0;
};
