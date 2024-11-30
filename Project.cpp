#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;
GameMechs* gameMechs;
Player* player;
char gameBoard[20][10];  //moved to GameMechs but still here as a failsafe

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

    gameMechs = new GameMechs();
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
        switch (input)
        {
        case ' ':
            exitFlag = true;
            gameMechs->setExitTrue();
            gameMechs->setLoseFlag();
            gameMechs->setInput(input);
            break;
        
        default:
        player->updatePlayerDir(input);
            gameMechs->setInput(input);
            break;
        }
    }
}

void RunLogic(void)
{
    for (int i = 0; i < gameMechs->getBoardSizeX(); i++)
    {
        for (int j = 0; j < gameMechs->getBoardSizeY(); j++)
        {
            // [TODO] Draw the game board here
            //place the player
            if (i == player->getPlayerPos().pos->x && j == player->getPlayerPos().pos->y)
            {
                gameBoard[i][j] = player->getPlayerPos().symbol;
            }
            //set food
            else if (i == gameMechs->getFoodX() && j == gameMechs->getFoodY())//compare food position with i and j
            {
                gameBoard[i][j] = gameMechs->getFoodSymbol();
            }
            //set border
            else if (i == 0 || i == gameMechs->getBoardSizeX() - 1 || j == 0 || j == gameMechs->getBoardSizeY() - 1)
            {
                gameBoard[i][j] = gameMechs->getBorderChar();
            }
            else
            {
                gameBoard[i][j] = ' ';
            }
        }
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    for(int i = 0; i < gameMechs->getBoardSizeX(); i++)
    {
        for(int j = 0; j < gameMechs->getBoardSizeY(); j++)
        {
            printf("%c", gameBoard[i][j]);
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
