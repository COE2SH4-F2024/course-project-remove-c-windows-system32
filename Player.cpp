#include "Player.h"

Player::Player()
{
    // default constructor
    mainGameMechsRef = new GameMechs();
    myDir = STOP;
    objPosArrayList* snake = new objPosArrayList();
    objPos playerPos = objPos(14, 7, '*');

    // more things
}


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    snake = new objPosArrayList();
    snake->insertHead(objPos(14, 7, '*'));
    snake->insertTail(objPos(13, 7, '*'));
    snake->insertTail(objPos(12, 7, '*'));

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
    return snake->getHead(); 
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
            myDir = ((myDir != RIGHT) && (myDir != STOP))? LEFT:RIGHT;
            break;

        case 'd':
            myDir = (myDir != LEFT)?RIGHT:LEFT;
            break;
    }

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    switch (myDir) //apply snake logic for movement
    {
    case UP:
        snake->insertHead(objPos(snake->getHead().pos->x, snake->getHead().pos->y - 1, '*'));
        snake->removeTail();
        break;
    case DOWN:
        snake->insertHead(objPos(snake->getHead().pos->x, snake->getHead().pos->y + 1, '*'));
        snake->removeTail();
        break;
    case LEFT:
        snake->insertHead(objPos(snake->getHead().pos->x - 1, snake->getHead().pos->y, '*'));
        snake->removeTail();
        break;
    case RIGHT:
        snake->insertHead(objPos(snake->getHead().pos->x + 1, snake->getHead().pos->y, '*'));
        snake->removeTail();
        break;
    default:
        break;
    }

    //Do the wraparound logic
    //If the snake goes off the board, it should wrap around to the other side
    if(snake->getHead().pos->x > mainGameMechsRef->getBoardSizeX() - 2)
    {
        snake->setHead(objPos(1, snake->getHead().pos->y, '*'));  
    }
    else if(snake->getHead().pos->x < 1)
    {
        snake->setHead(objPos(mainGameMechsRef->getBoardSizeX() - 2, snake->getHead().pos->y, '*'));
    }

    if(snake->getHead().pos->y > mainGameMechsRef->getBoardSizeY() - 2)
    {
        snake->setHead(objPos(snake->getHead().pos->x, 1, '*'));
    }
    else if(snake->getHead().pos->y < 1)
    {
        snake->setHead(objPos(snake->getHead().pos->x, mainGameMechsRef->getBoardSizeY() - 2, '*'));
    }
}

// More methods to be added

Player::Player(const Player& other)
{
    //copy constructor
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
    myDir = other.myDir;
    mainGameMechsRef = other.mainGameMechsRef;
    return *this;
}

int Player::getSnakeSize() const
{
    return snake->getSize();
}

objPos Player::getElement(int index) const
{
    return snake->getElement(index);
}

void Player::growSnake()
{
    //grow the snake by one
    //add a new element to the snake
    //the new element should be the same as the last element
    snake->insertTail(snake->getTail());
}