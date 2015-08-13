#include "Fighter.h"

class Robot : public Fighter
{
    private:
        int current_energy;
        int max_energy;
        int bonus_damage;

    public:
        Robot(string name, int hp, int strength, int speed, int magic);
        ~Robot(void);
        int getDamage();
        bool useAbility();
        bool isSimplified();
        void reset();
};
