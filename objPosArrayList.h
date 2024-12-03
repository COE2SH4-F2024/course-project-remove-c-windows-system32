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
        //rule of 6/4 stuff
        objPosArrayList();
        ~objPosArrayList();
        objPosArrayList(const objPosArrayList& other);
        objPosArrayList& operator=(const objPosArrayList& other);

        //getters
        int getSize() const;
        objPos getHead() const;
        objPos getTail() const;
        objPos getElement(int index) const;

        //setters
        void setElement(int index, objPos thisPos);
        void setHead(objPos thisPos);
        void setTail(objPos thisPos);

        //insertions
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);

        //removals
        void removeHead();
        void removeTail();
        
};

#endif