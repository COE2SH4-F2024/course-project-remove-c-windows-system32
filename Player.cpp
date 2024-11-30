#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    objPosArrayList* List = new objPosArrayList();

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    delete mainGameMechsRef;
    
}

objPos Player::getPlayerPos() const
{
    return playerPos; 
}

void Player::updatePlayerDir(char input)
{
        // PPA3 input processing logic  
    //get the input from the user and update the direction accordingly
    switch (input)
    {
    case 'w':
            myDir = UP;
            break;
        
        case 's':
            myDir = DOWN;
            break;
        
        case 'a':
            myDir = LEFT;
            break;

        case 'd':
            myDir = RIGHT;
            break;
    }
        

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

// More methods to be added