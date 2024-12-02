#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

class Food
{
    private:
        objPos foodPos;
        GameMechs* mechs;
        objPosArrayList* foodList;
        
    public:
        Food();
        Food(GameMechs* mechs);
        ~Food();
        void cook(); //Generate food function
        objPos getFoodPos() const;
        objPos getSpecialFoodPos(int randNum) const;
};