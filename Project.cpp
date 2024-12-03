#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;
GameMechs* gameMechs;
Player* player;
Food* food;
char gameBoard[15][30];  //planning to move to GameMechs but not moved yet until we make this work 
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
    food = new Food(gameMechs);

    gameMechs->setGrid(player->getSnake(), food->getFoodList());
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
        case ' ':
            gameMechs->setExitTrue();
            gameMechs->setLoseFlag();
            break;
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
        //debug key to be removed later
        case 'b':
            food->cook();
            gameMechs->setGrid(player->getSnake(), food->getFoodList());
            break;
        case 'n':
            player->growSnake();
            break;
    
    default:
        break;
    }
    gameMechs->clearInput();//clear the input after processing
}

void RunLogic(void)
{
    player->movePlayer();
    if(player->hasEaten(food->getFoodPos()) == true)
    {
        food->cook();
        printf("Food eaten\n");//
    }
    player->checkCollision();
    

    //Check if the player has hit the exit key
    if(gameMechs->getExitFlagStatus() == true)
    {
        exitFlag = true;
    }
    else if(gameMechs->getScore() >= 10)
    {
        exitFlag = true;
    }


    for (int i = 0; i < gameMechs->getBoardSizeY(); i++)
    {
        for (int j = 0; j < gameMechs->getBoardSizeX(); j++)
        {
            // [TODO] Draw the game board here
            //place the player
            // if (j == player->getPlayerPos().pos->x && i == player->getPlayerPos().pos->y)
            // {
            //     gameBoard[i][j] = player->getPlayerPos().symbol;
            // }
            // //set food
            if (j == food->getFoodPos().pos->x && i == food->getFoodPos().pos->y)//compare food position with i and j
            {
                gameBoard[i][j] = food->getFoodPos().symbol;
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
    //add the snakebody to the board
    for (int i = 0; i < player->getSnakeSize(); i++)
    {
        gameBoard[player->getElement(i).pos->y][player->getElement(i).pos->x] = player->getElement(i).symbol;
    }
    //add the food to the board
    for (int i = 0; i < food->getFoodListSize(); i++)
    {
        gameBoard[food->getFoodListElement(i).pos->y][food->getFoodListElement(i).pos->x] = food->getFoodListElement(i).symbol;
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
    printf("Score: %d\nGame Speed: %s\n", gameMechs->getScore(), gameSpeed[speed].c_str());
    printf("Press 1-5 to adjust game speed\nPress space to exit\n");
}

void LoopDelay(void)
{
    switch (speed)
    {
    case SUPER_SLOW:
        MacUILib_Delay(200000); // 0.2s delay
        break;

    case SLOW:
        MacUILib_Delay(150000); // 0.15s delay
        break;

    case MEDIUM:
        MacUILib_Delay(DELAY_CONST); // 0.1s delay
        break;

    case FAST:
        MacUILib_Delay(150000); // 0.05s delay
        break;

    case SUPER_FAST:
        MacUILib_Delay(10000); // 0.01s delay
        break;

    default:
        // Default to MEDIUM speed
        MacUILib_Delay(DELAY_CONST); // 0.1s delay
        break;
    }

}


void CleanUp()
{

    MacUILib_clearScreen();

    if (gameMechs->getLoseFlagStatus() == false)
    {
        printf("You win\n");
        // ASCII art for win screen
        std::cout << "Congratulations!!!\nYou Win\nYay!!! :)\n\n";
    }
    else 
    {
        printf("You lose\n");
        // ASCII art for game over screen
        std::cout << "GAME OVER!!!\nYou Lose\nWomp Womp :( \n\n";
    }

    // Clean up dynamically allocated memory
    delete player;
    delete gameMechs;
    MacUILib_uninit();
}
