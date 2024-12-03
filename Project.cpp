#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

//Global variables
bool exitFlag;
GameMechs* gameMechs;
Player* player;
Food* food;
char gameBoard[15][30];  //planning to move to GameMechs but not moved yet until we make this work 
std::string gameSpeed[5] = {"Super Slow", "Slow","Medium", "Fast", "Super Fast"};
enum GameSpeed {SUPER_SLOW, SLOW, MEDIUM, FAST, SUPER_FAST};
GameSpeed speed;

//Function prototypes
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


//Main function (stuff happens here)
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

//initialize things
void Initialize(void)
{
    // Initialize the MacUILib
    MacUILib_init();
    MacUILib_clearScreen();

    //instansiate the needed objects
    gameMechs = new GameMechs();
    player = new Player(gameMechs);
    food = new Food(gameMechs);

    //prep the game board
    gameMechs->setGrid(player->getSnake(), food->getFoodList());
    exitFlag = gameMechs->getExitFlagStatus();
    speed = MEDIUM;
    


}

void GetInput(void)
{
    // Check if there is a character in the input buffer
    if(MacUILib_hasChar())
    {
        //save the character in the input buffer
        char input = MacUILib_getChar();

        //send the input to the processing chamber
        gameMechs->setInput(input);
        player->updatePlayerDir();
    }
    
    //some external input processing
    switch (gameMechs->getInput())
    {
        //exit key
        case ' ':
            gameMechs->setExitTrue();
            gameMechs->setLoseFlag();
            break;
        //speed keys
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

    //clear the input after processing
    gameMechs->clearInput();
}

//run logic, where the magic happens
void RunLogic(void)
{
    //move the player accordingly based on direction
    player->movePlayer();

    //check if the player has eaten any food and save its index
    int eaten = player->hasEaten(food->getFoodList());

    //if the index is not -1, cook some food
    if(eaten != -1)
    {
        //let him cook, (im a great chef)
        food->cook(eaten, gameMechs, player->getSnake());
    }
    //check if the player has collided with itself
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

    //update the game board
    for (int i = 0; i < gameMechs->getBoardSizeY(); i++)
    {
        for (int j = 0; j < gameMechs->getBoardSizeX(); j++)
        {
            // [TODO] Draw the game board here
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

//draw the screen
void DrawScreen(void)
{
    //clear screen
    MacUILib_clearScreen();
    //loop through the arrays and print each line
    for(int i = 0; i < gameMechs->getBoardSizeY(); i++)
    {
        for(int j = 0; j < gameMechs->getBoardSizeX(); j++)
        {
            printf("%c", gameBoard[i][j]);
        }
        printf("\n");
    }
    //print the score and game speed
    printf("Score: %d\nGame Speed: %s\n", gameMechs->getScore(), gameSpeed[speed].c_str());
    printf("Press 1-5 to adjust game speed\nPress space to exit\nBeware of the X!!!");
}

void LoopDelay(void)
{
    //delay based on the game speed
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

//clear everything up
void CleanUp()
{
    //clear the screen
    MacUILib_clearScreen();

    //check if the player won or lost
    if (gameMechs->getLoseFlagStatus() == false)
    {
        // win screen
        std::cout << "Congratulations!!!\nYou Win\nYay!!! :)\n\n";
    }
    else 
    {
        //lose screen
        std::cout << "GAME OVER!!!\nYou Lose\nWomp Womp :( \n\n";
    }

    // Clean up dynamically allocated memory (no memory leakage allowed here)
    delete player;
    delete gameMechs;
    delete food;
    MacUILib_uninit();
}

//done :)
//pls give 100% 🥺🥺🥺