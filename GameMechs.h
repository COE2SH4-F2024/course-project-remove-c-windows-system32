#ifndef GAMEMECHS_H
#define GAMEMECHS_H
#define BOARD_SIZE_X 30
#define BOARD_SIZE_Y 15

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "MacUILib.h"

using namespace std;

class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;
        char board[BOARD_SIZE_Y][BOARD_SIZE_X];
        char borderChar;

        int boardSizeX;
        int boardSizeY;

        objPos food;

    public:

        // Rule of 6/4 stuff
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // is this one needed at all? Why or why not?
        GameMechs(const GameMechs& other);
        GameMechs& operator=(const GameMechs& other);
        
        //getters
        bool getExitFlagStatus() const; 
        bool getLoseFlagStatus() const;
        char getInput() const;
        int getRand(int min, int max);
        int getBoardSizeX() const;
        int getBoardSizeY() const;
        int getScore() const;
        char getBoardElement(int x, int y) const;
        char getBorderChar() const;
        int GetRandomNumber(int min, int max);
        
        //setters
        void setExitTrue();
        void setLoseFlag();
        void setInput(char this_input);
        void clearInput();
        void incrementScore();
        void setBoardElement(int x, int y, char thisChar);
        void CheckCollision(objPosArrayList* snake, objPos food);
        void setGrid(objPosArrayList* snake, objPosArrayList* foods);        
};

#endif