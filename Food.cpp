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
    foodPos.setObjPos(mechs->getRand(1,28), mechs->getRand(1,13), 'O');
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

void Food::cook()
{
    //generate the food at a random location
    foodPos.setObjPos(mechs->getRand(1,28),mechs->getRand(1,13) , 'O');
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



