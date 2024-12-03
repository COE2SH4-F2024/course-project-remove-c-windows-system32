#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

class Food
{
    private:
        GameMechs* mechs;
        objPosArrayList* foodList;
        objPos foodPos;
        
    public:
        Food();
        Food(GameMechs* mechs);
        ~Food();
        void cook(int index, GameMechs* mechs, objPosArrayList* snake); //Generate food function
        objPos getFoodPos() const;
        objPos getFoodListElement(int index) const;
        objPosArrayList* getFoodList() const;
        void setFoodListElement(int index, objPos thisPos);
        void setFoodListElement(int index, int xPos, int yPos, char sym);
        void setFoodListElement(int index, int xPos, int yPos);
        int getFoodListSize() const;


};