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

        Player();
        Player(GameMechs* thisGMRef);
        ~Player();

        objPos getPlayerPos() const; // Upgrade this in iteration 3.       
        void updatePlayerDir();
        void movePlayer();


        // More methods to be added here
        Player(const Player& other);
        Player& operator=(const Player& other);
        int getSnakeSize() const;
        objPos getElement(int index) const;



    private:
        objPos playerPos; // Upgrade this in iteration 3.       
        enum Dir myDir;
        objPosArrayList* snake; // This is the snake body list //Will be upgraded in iteration 3
        bool moved; // This is a flag to indicate if the snake has moved or not

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif