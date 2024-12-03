#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos;        
        char symbol;

        //Constructors
        objPos();
        objPos(int xPos, int yPos, char sym);
        
        //Member functions for the rule of 6/4
        ~objPos();
        objPos(const objPos& other);
        objPos& operator=(const objPos& other);
        
        //setters
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        //getters
        objPos getObjPos() const;
        char getSymbol() const;
        bool isPosEqual(const objPos& refPos) const;
        char getSymbolIfPosEqual(const objPos& refPos) const;
        
};

#endif