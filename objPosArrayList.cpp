#include "objPosArrayList.h"

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    listSize = 1;
    arrayCapacity = ARRAY_MAX_CAP;

    for(int i = 0; i < arrayCapacity; i++)
    {
        aList[i] = objPos();
    }


}

objPosArrayList::objPosArrayList(int size)
{
    aList = new objPos[size];
    listSize = 1;
    arrayCapacity = size;

    for(int i = 0; i < arrayCapacity; i++)
    {
        aList[i] = objPos();
    }

}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

// [TODO] Implement the missing special member functions to meet the minimum four rule
//copy constructor
objPosArrayList::objPosArrayList(const objPosArrayList& other)
{
    //do copy constructor stuff

    objPos* aList = new objPos[other.arrayCapacity];
    listSize = other.listSize;
    arrayCapacity = other.arrayCapacity;

    for(int i = 0; i < arrayCapacity; i++)
    {
        aList[i] = other.aList[i];
    }

}

//copy assignment operator
objPosArrayList& objPosArrayList::operator=(const objPosArrayList& other)
{

}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize < arrayCapacity)
    {
        for(int i = listSize; i > 0; i--)
        {
            aList[i] = aList[i-1];
        }
        aList[0] = thisPos;
        listSize++;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize < arrayCapacity)
    {
        aList[listSize] = thisPos;
        listSize++;
    }
}

void objPosArrayList::removeHead()
{
    if(listSize > 0)
    {
        for(int i = 0; i < listSize-1; i++)
        {
            aList[i] = aList[i+1];
        }
        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    if(listSize > 0)
    {
        listSize--;
    }
}

objPos objPosArrayList::getHead() const
{
    return aList[0];
}

objPos objPosArrayList::getTail() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}

void objPosArrayList::setElement(int index, objPos thisPos)
{
    aList[index] = thisPos;
}

void objPosArrayList::setHead(objPos thisPos)
{
    aList[0] = thisPos;
}

void objPosArrayList::setTail(objPos thisPos)
{
    aList[listSize - 1] = thisPos;
}