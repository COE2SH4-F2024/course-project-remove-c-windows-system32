#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;
GameMechs* gameMechs;
Player* player;
char gameBoard[20][10];  // [TODO] Initialize the game board here

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    player = new Player(gameMechs);
    Player* player = new Player(gameMechs);

    player->getPlayerPos().setObjPos(5, 5, '@');

    exitFlag = gameMechs->getExitFlagStatus();
}

void GetInput(void)
{
    if(MacUILib_hasChar())
    {
        char input = MacUILib_getChar();
        if(input == ' ')
        {
            exitFlag = true;
        }
    }
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    for (int i = 0; i < gameMechs->getBoardSizeX(); i++)
    {
        for (int j = 0; j < gameMechs->getBoardSizeY(); j++)
        {
            // [TODO] Draw the game board here
            //first draw the player and object, and then the rest of the board
            if (i == player->getPlayerPos().pos->x && j == player->getPlayerPos().pos->y)
            {
                printf("%c", player->getPlayerPos().symbol);
            }
            //check and print out food
            else if ()//stuff here
            {
                printf("");
            }
            //print border
            else if (i == 0 || i == gameMechs->getBoardSizeX() - 1 || j == 0 || j == gameMechs->getBoardSizeY() - 1)
            {
                printf("#");
            }
            else
            {
                printf("%c", gameBoard[i][j]);
            }
        }
        printf("\n");
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
