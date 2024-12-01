#include "GameMechs.h"
#include <stdio.h>


GameMechs::GameMechs()
{
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = BOARD_SIZE_X;
    boardSizeY = BOARD_SIZE_Y;
    borderChar = '#';
    food.symbol = 'O';
    //create food object
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    borderChar = '#';
    //create food object
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    delete &food;
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
   score++; 
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;  
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}

// More methods should be added here
void GameMechs::Cook(objPosArrayList* snake)
{
    //

}

void GameMechs::CheckCollision(objPosArrayList* snake)
{
    //

}

int GameMechs::GetRandomNumber(int min, int max)
{
    printf("Actually implement this function\n");
    return 0;
}

int GameMechs::getFoodX() const
{
    return food.pos->x;
}

int GameMechs::getFoodY() const
{
    return food.pos->y;
}

char GameMechs::getBoardElement(int x, int y) const
{
    return board[x][y];
}

void GameMechs::setBoardElement(int x, int y, char thisChar)
{
    board[x][y] = thisChar;
}

char GameMechs::getBorderChar() const
{
    return borderChar;
}

GameMechs::GameMechs(const GameMechs& other)
{
    input = other.input;
    exitFlag = other.exitFlag;
    loseFlag = other.loseFlag;
    score = other.score;
    boardSizeX = other.boardSizeX;
    boardSizeY = other.boardSizeY;
    borderChar = other.borderChar;
    food = other.food;
}

GameMechs& GameMechs::operator=(const GameMechs& other)
{
    if(this == &other)
    {
        return *this;
    }
    
    input = other.input;
    exitFlag = other.exitFlag;
    loseFlag = other.loseFlag;
    score = other.score;
    boardSizeX = other.boardSizeX;
    boardSizeY = other.boardSizeY;
    borderChar = other.borderChar;
    food = other.food;
    
    return *this;
}

char GameMechs::getFoodSymbol() const
{
    return food.symbol;
}

//generates a number in the rangr of [min, max]
int GameMechs::getRand(int min, int max)
{
    return rand() % (max - min + 1) + min;
}