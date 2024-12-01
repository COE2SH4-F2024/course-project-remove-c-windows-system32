#include "Food.h"

Food::Food()
{
    foodPos = objPos();
    mechs = new GameMechs();
    foodPos.setObjPos(mechs->getRand(1,28), mechs->getRand(1,13), 'O');
    specialFoodPos = objPos();

}

Food::Food(GameMechs* mechs)
{
    //set the x and y coordinates of the food
    foodPos = objPos();
    foodPos.setObjPos(mechs->getRand(1,28), mechs->getRand(1,13), 'O');
    //specialFoodPos = objPos();
    //specialFoodPos.setObjPos(x, y, 'X');
}

Food::~Food()
{
    //delete the food objects
    delete &foodPos;
    delete &specialFoodPos;
}

void Food::cook()
{
    //generate the food at a random location
    foodPos.setObjPos(mechs->getRand(1,29),mechs->getRand(1,14) , 'O');
}

objPos Food::getFoodPos() const
{
    return foodPos;
}

