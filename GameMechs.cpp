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
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    borderChar = '#';
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //was needed before, now not sure but we leave it in for now
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

void GameMechs::CheckCollision(objPosArrayList* snake, objPos food)
{
    //

}

int GameMechs::GetRandomNumber(int min, int max)
{
    printf("Actually implement this function\n");
    return 0;
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


//generates a number in the rangr of [min, max]
int GameMechs::getRand(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void GameMechs::setGrid(objPosArrayList* snake, objPosArrayList* foods)
{
    //set the food on the grid without any overlap

    int coordinates[5][2]; //stores the coordinates of each item in the food list 
    for(int i = 0; i < 5; i++)
    {
        int x = getRand(1,28);
        int y = getRand(1,13);
        char sym = 'O';
        char sym2 = 'X';
        for(int j = 0; j < i; j++)
        {
            if(x == coordinates[j][0] && y == coordinates[j][1])
            {
                i--;
                break;
            }
        }
        for(int j = 0; j < snake->getSize(); j++)
        {
            if(x == snake->getElement(j).pos->x && y == snake->getElement(j).pos->y)
            {
                i--;
                break;
            }
        }

        if(i < 4)
        {
            foods->setElement(i, objPos(x, y, sym));
        }
        else if (i == 4)
        {
            foods->setElement(i, objPos(x, y, sym2));
        }
    }
}