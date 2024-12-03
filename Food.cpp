#include "Food.h"

Food::Food()
{
    foodPos = objPos();
    mechs = new GameMechs();
    foodList = new objPosArrayList();
    foodPos.setObjPos(mechs->getRand(1,28), mechs->getRand(1,13), 'O');

}

Food::Food(GameMechs* mechs)
{
    //set the x and y coordinates of the food
    foodPos = objPos();
    foodList = new objPosArrayList();

    foodList->insertHead(objPos(mechs->getRand(1,28), mechs->getRand(1,13), 'O'));
    foodList->insertTail(objPos(mechs->getRand(1,28), mechs->getRand(1,13), 'O'));
    foodList->insertTail(objPos(mechs->getRand(1,28), mechs->getRand(1,13), 'O'));
    foodList->insertTail(objPos(mechs->getRand(1,28), mechs->getRand(1,13), 'O'));
    foodList->insertTail(objPos(mechs->getRand(1,28), mechs->getRand(1,13), 'X'));

}

Food::~Food()
{
    //delete the food objects
    delete &foodList;
}

void Food::cook(int index, GameMechs* mechs, objPosArrayList* snake)
{
    //generate the food at a random location that doesn't overlap with the snake or other food
    int coordinates[5][2]; //stores the coordinates of each item in the food list 
    for(int i = 0; i < 5; i++)
    {
        int x = mechs->getRand(1,28);
        int y = mechs->getRand(1,13);
        for(int j = 0; j < i; j++)
        {
            if(x == coordinates[j][0] && y == coordinates[j][1])
            {
                i--;
                break;
            }
        }
        for(int j = 0; j < snake->getSize(); j++)
        {
            if(x == snake->getElement(j).pos->x && y == snake->getElement(j).pos->y)
            {
                i--;
                break;
            }
        }

    setFoodListElement(index, objPos(x, y, getFoodListElement(index).symbol));
    }
}

objPos Food::getFoodPos() const
{
    return foodPos;
}

objPos Food::getFoodListElement(int index) const
{
    return foodList->getElement(index);
}

//set the objPos of the food directly
void Food::setFoodListElement(int index, objPos thisPos)
{
    foodList->setElement(index, thisPos);
}

//set the x and y coordinates of the food and the symbol directly
void Food::setFoodListElement(int index, int x, int y, char sym)
{
    foodList->setElement(index, objPos(x, y, sym));
}

//set the x and y coordinates of the food but keep the symbol the same
void Food::setFoodListElement(int index, int x, int y)
{
    foodList->setElement(index, objPos(x, y, foodList->getElement(index).symbol));
}

int Food::getFoodListSize() const
{
    return foodList->getSize();
}

objPosArrayList* Food::getFoodList() const
{
    return foodList;
}



