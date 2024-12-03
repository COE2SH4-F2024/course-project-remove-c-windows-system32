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

        //Member functions for the rule of 6/4
        Food();
        Food(GameMechs* mechs);
        ~Food();
        Food(const Food& other);
        Food& operator=(const Food& other);

        //getters
        objPos getFoodPos() const;
        objPos getFoodListElement(int index) const;
        objPosArrayList* getFoodList() const;
        int getFoodListSize() const;

        //setters
        void setFoodListElement(int index, objPos thisPos);
        void setFoodListElement(int index, int xPos, int yPos, char sym);
        void setFoodListElement(int index, int xPos, int yPos);

        //generate food
        void cook(int index, GameMechs* mechs, objPosArrayList* snake); //Generate food function

};