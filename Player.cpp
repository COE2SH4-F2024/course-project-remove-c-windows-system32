#include "Player.h"

Player::Player()
{
    // default constructor
    mainGameMechsRef = new GameMechs();
    myDir = STOP;
    objPosArrayList* snake = new objPosArrayList(10);
    objPos playerPos = objPos(14, 7, '*');

    // more things
}


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    snake = new objPosArrayList(10);
    playerPos = objPos(14, 7, '*');  // Initialize the member variable

    // more things
}


Player::~Player()
{
    // delete any heap members here
    delete mainGameMechsRef;
    delete snake;
    
}

objPos Player::getPlayerPos() const
{
    return playerPos; 
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic  
    //get the input from the user and update the direction accordingly
    char input = mainGameMechsRef->getInput();

    switch (input)
    {
    case 'w':
            myDir = (myDir != DOWN)? UP:DOWN;
            break;
        
        case 's':
            myDir = (myDir != UP)? DOWN:UP;
            break;
        
        case 'a':
            myDir = (myDir != RIGHT)? LEFT:RIGHT;
            break;

        case 'd':
            myDir = (myDir != LEFT)?RIGHT:LEFT;
            break;
    }

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    switch (myDir)
    {
    case UP:
        playerPos.pos->y--;
        break;
    case DOWN:
        playerPos.pos->y++;
        break;
    case LEFT:
        playerPos.pos->x--;
        break;
    case RIGHT:
        playerPos.pos->x++;
        break;
    default:
        break;
    }

    //Do the wraparound logic
    playerPos.pos->x %= mainGameMechsRef->getBoardSizeX(); //This is here as a failsafe because sometimes funky stuff happened in PPA3 without this statement
    playerPos.pos->y %= mainGameMechsRef->getBoardSizeY();

    //Proper wraparound logic
    if(playerPos.pos->x > mainGameMechsRef->getBoardSizeX() - 2)
    {
        playerPos.pos->x = 1;
    }
    else if(playerPos.pos->x < 1)
    {
        playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
    }

    if(playerPos.pos->y > mainGameMechsRef->getBoardSizeY() - 2)
    {
        playerPos.pos->y = 1;
    }
    else if(playerPos.pos->y < 1)
    {
        playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
    }
        
}

// More methods to be added

Player::Player(const Player& other)
{
    //copy constructor
    playerPos = other.playerPos;
    myDir = other.myDir;
    mainGameMechsRef = other.mainGameMechsRef;
}

Player& Player::operator=(const Player& other)
{
    //copy assignment operator
    if(this == &other)
    {
        return *this;
    }
    playerPos = other.playerPos;
    myDir = other.myDir;
    mainGameMechsRef = other.mainGameMechsRef;
    return *this;
}