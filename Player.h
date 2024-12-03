#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        //member functions
        Player();
        Player(GameMechs* thisGMRef);
        ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        //getters
        objPos getPlayerPos() const;      
        int getSnakeSize() const;
        objPos getElement(int index) const;
        objPosArrayList* getSnake() const;

        //setters
        void updatePlayerDir();

        //other functions
        void movePlayer();
        void checkCollision();
        int hasEaten(objPosArrayList* foods);
        void growSnake();


    private:      
        enum Dir myDir;
        objPosArrayList* snake; // This is the snake body list //Will be upgraded in iteration 3

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif