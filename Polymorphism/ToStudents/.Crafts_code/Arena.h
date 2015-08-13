#pragma once
#include "ArenaInterface.h"
#include <vector>
class Arena : public ArenaInterface
{
    private:
        vector <FighterInterface*> Fighters;
    public:
        Arena(void);
        ~Arena(void);
        bool addFighter(string name);
        bool removeFighter(string name);
        FighterInterface *getFighter(string name);
        int getSize();
};
