#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList;
        int listSize;
        int arrayCapacity;

    public:
        objPosArrayList();
        ~objPosArrayList();
        //rule of 6/4 stuff
        objPosArrayList(const objPosArrayList& other);
        objPosArrayList& operator=(const objPosArrayList& other);

        int getSize() const;
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        objPos getHead() const;
        objPos getTail() const;
        objPos getElement(int index) const;
        void setElement(int index, objPos thisPos);
        void setHead(objPos thisPos);
        void setTail(objPos thisPos);
};

#endif