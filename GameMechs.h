#ifndef GAMEMECHS_H
#define GAMEMECHS_H
#define BOARD_SIZE_X 30
#define BOARD_SIZE_Y 15

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

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
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // is this one needed at all? Why or why not?
        
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        char getInput() const;
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        int getScore() const;
        void incrementScore();

        char getBoardElement(int x, int y) const;
        void setBoardElement(int x, int y, char thisChar);
        char getBorderChar() const;
        
        // More methods should be added here

        // [TODO] Implement the missing special member functions to meet the minimum four rule
        GameMechs(const GameMechs& other);
        GameMechs& operator=(const GameMechs& other);
        void Cook(objPosArrayList* snake); //Spawn food (Cooking) 
        void CheckCollision(objPosArrayList* snake);
        int GetRandomNumber(int min, int max);
        int getFoodX() const;
        int getFoodY() const;
        char getFoodSymbol() const;
};

#endif