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

// Destructor
Player::~Player()
{
    // delete any heap members here
    delete mainGameMechsRef;
    delete snake;
    
}

//copy constructor
Player::Player(const Player& other)
{
    myDir = other.myDir;
    mainGameMechsRef = other.mainGameMechsRef;
}

//copy assignment operator
Player& Player::operator=(const Player& other)
{
    if(this == &other)
    {
        return *this;
    }
    myDir = other.myDir;
    mainGameMechsRef = other.mainGameMechsRef;
    return *this;
}

//getters
objPosArrayList* Player::getSnake() const
{
    return snake;
}

int Player::getSnakeSize() const
{
    return snake->getSize();
}

objPos Player::getElement(int index) const
{
    return snake->getElement(index);
}

objPos Player::getPlayerPos() const
{
    return snake->getHead(); 
}

//setters
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

//other functions
void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    //apply snake logic for movement
    switch (myDir) //for each direction, insert a new head accordingly and remove the tail
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

void Player::growSnake()
{
    //add a new tail element to the snake where the old tail was
    snake->insertTail(snake->getTail());
}

//check if the snake has eaten the food, and then return the index of the food that was eaten
int Player::hasEaten(objPosArrayList* foods)
{
    //check if the snake has eaten the food
    //if the snake has eaten the food, grow the snake and increment the score
    //loop through the food list and check if the snake head is at the same position as the food
    for(int i = 0; i < 5; i++)
    {
        //if the snake has eaten the food, grow the snake and increment the score
        if(snake->getHead().isPosEqual(foods->getElement(i)))
        {
            growSnake();
            mainGameMechsRef->incrementScore();
            //if the snake eats the X, the player loses
            if (foods->getElement(i).symbol == 'X')
            {
                mainGameMechsRef->setLoseFlag();
                mainGameMechsRef->setExitTrue();
            }
            //return the index of the food that was eaten
            return i;
        }
    }
    //return -1 if the snake has not eaten any food
    return -1;
}

//check if the snake has collided with itself
void Player::checkCollision()
{
    //check if the snake has collided with itself
    //if the snake has collided with itself, the player loses
    //loop through the snake and check if the head is at the same position as any other part of the snake
    for(int i = 1; i < snake->getSize(); i++)
    {
        //if the head is in the same position as any other part of the snake, the player loses
        if(snake->getHead().isPosEqual(snake->getElement(i)))
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }
}
