#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;
GameMechs* gameMechs;
Player* player;
char gameBoard[10][20];  //planning to move to GameMechs but not moved yet until we make this work 
std::string gameSpeed[5] = {"Super Slow", "Slow","Medium", "Fast", "Super Fast"};
enum GameSpeed {SUPER_SLOW, SLOW, MEDIUM, FAST, SUPER_FAST};
GameSpeed speed;


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
    //Player* player = new Player(gameMechs);

    exitFlag = gameMechs->getExitFlagStatus();

    speed = MEDIUM;
    


}

void GetInput(void)
{
    if(MacUILib_hasChar())
    {
        char input = MacUILib_getChar();

        gameMechs->setInput(input);
        player->updatePlayerDir();

        //Trying to think of a place to check exit flag, probably in RunLogic
    }
    
    switch (gameMechs->getInput())
    {
        case '1':
            speed = SUPER_SLOW;
            break;
        case '2':
            speed = SLOW;
            break;
        case '3':
            speed = MEDIUM;
            break;
        case '4':
            speed = FAST;
            break;
        case '5':
            speed = SUPER_FAST;
            break;
    
    default:
        break;
    }
}

void RunLogic(void)
{
    player->movePlayer();
    //gameMechs->CheckCollision(player->snake); //Reminder only really needs to head of the snake collides with things
    //gameMechs->Cook(player->snake);//only of the food is eaten

    //Check if the player has hit the exit key
    if(gameMechs->getExitFlagStatus() == true)
    {
        exitFlag = true;
    }

    for (int i = 0; i < gameMechs->getBoardSizeY(); i++)
    {
        for (int j = 0; j < gameMechs->getBoardSizeX(); j++)
        {
            // [TODO] Draw the game board here
            //place the player
            if (j == player->getPlayerPos().pos->x && i == player->getPlayerPos().pos->y)
            {
                gameBoard[i][j] = player->getPlayerPos().symbol;
            }
            //set food
            else if (j == gameMechs->getFoodX() && i == gameMechs->getFoodY())//compare food position with i and j
            {
                gameBoard[i][j] = gameMechs->getFoodSymbol();
            }
            //set border
            else if (j == 0 || j == gameMechs->getBoardSizeX() - 1 || i == 0 || i == gameMechs->getBoardSizeY() - 1)
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
    for(int i = 0; i < gameMechs->getBoardSizeY(); i++)
    {
        for(int j = 0; j < gameMechs->getBoardSizeX(); j++)
        {
            printf("%c", gameBoard[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\nGame Speed: %s", gameMechs->getScore(), gameSpeed[speed].c_str());
}

void LoopDelay(void)
{
    //MacUILib_Delay(DELAY_CONST); // 0.1s delay

    switch (speed)
    {
    case SUPER_SLOW:
        MacUILib_Delay(200000); // 0.2s delay
        break;

    case SLOW:
        MacUILib_Delay(150000); // 0.15s delay
        break;

    case MEDIUM:
        MacUILib_Delay(100000); // 0.1s delay
        break;

    case FAST:
        MacUILib_Delay(150000); // 0.05s delay
        break;

    case SUPER_FAST:
        MacUILib_Delay(10000); // 0.01s delay
        break;

    default:
        // Default to MEDIUM speed
        MacUILib_Delay(100000); // 0.1s delay
        break;
    }

}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
