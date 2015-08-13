#include "Fighter.h"

class Archer : public Fighter
{
    private:
        int start_speed;
    public:
        Archer(string name, int hp, int strength, int speed, int magic);
        ~Archer(void);
        int getDamage();
        void reset();
        bool useAbility();
        bool isSimplified();
};
