#include "objPos.h"
#include "GameMechs.h"

class Food
{
    private:
        objPos foodPos;
        objPos specialFoodPos;
        GameMechs* mechs;
        
    public:
        Food();
        Food(GameMechs* mechs);
        ~Food();
        void cook(); //Generate food function
        objPos getFoodPos() const;
        objPos getSpecialFoodPos(int randNum) const;
};