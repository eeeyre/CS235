#include "Fighter.h"
class Cleric : public Fighter
{
    private:
        int mana;
        int max_mana;

    public:
        Cleric(string name, int healthh, int strength, int speed, int magic);
        ~Cleric(void);

        int getDamage();
        void regenerate();
        bool useAbility();
        bool isSimplified();
        void reset();
};
