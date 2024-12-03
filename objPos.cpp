#include "objPos.h"

objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Rule of 6 minimun 4 stuff
//Copy Constructor
objPos::objPos(const objPos& other)
{
    pos = new Pos;
    pos->x = other.pos->x;
    pos->y = other.pos->y;
    symbol = other.symbol;
}
//Copy assignment operator
objPos& objPos::operator=(const objPos& other)
{
    if(this == &other)
    {
        return *this;
    }
    
    pos->x = other.pos->x;
    pos->y = other.pos->y;
    symbol = other.symbol;
}
//Destructor
objPos::~objPos()
{
    delete pos;
}

//setters
void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

//getters
objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

//Check if the position is equal to the reference position
bool objPos::isPosEqual(const objPos& refPos) const
{
    return (pos->x == refPos.pos->x && pos->y == refPos.pos->y);
}

//Get the symbol if the position is equal to the reference position
char objPos::getSymbolIfPosEqual(const objPos& refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    //return NULL if the position is not equal
    else
        return 0;
}
