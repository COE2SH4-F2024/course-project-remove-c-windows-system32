#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    List = new objPosArrayList();

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    delete List;
}

void Player::getPlayerPos(objPos &returnPos) const
{
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic          
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

// More methods to be added