#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"
#include "Food.h"



using namespace std;

#define DELAY_CONST 100000

Player *myPlayer; // Gloabla pointer meant to instantiate a player object on heap
GameMechs *myGM; 
Food *myFood;

struct objPos myObj;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM-> getExitFlagStatus() == false)  
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

    myGM = new GameMechs();
    myPlayer = new Player(myGM); // creating player object on the heap
    myFood = new Food();
    myFood -> generateFood(myPlayer->getPlayerPos());


}

void GetInput(void)
{
    myGM -> collectAsyncInput(myFood, myPlayer->getPlayerPos());
    // for debugging key of random food
}

void RunLogic(void)
{

    myPlayer -> updatePlayerDir();
    myPlayer -> movePlayer();
    myGM -> clearInput();
    //add movePlayer
    //add speed control

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  

    objPos playerPos = myPlayer -> getPlayerPos(); // goes into copy assignement operator
    objPos foodPos = myFood -> getFoodPos();
    MacUILib_printf("Player [x, y, sym] = [%d, %d, %c, ]\n", playerPos.pos->x, playerPos.pos->y, playerPos.symbol);

    int j, i;

    for (i=0; i<=myGM ->getBoardSizeY();)
    {
        if (i==0 || i==myGM ->getBoardSizeY())
        {
            for (j=0; j<= myGM ->getBoardSizeX(); j++)
            {
                MacUILib_printf("#");
            }

            MacUILib_printf("\n");
            i++;
        }

        else
        {
           for (j=0; j<=myGM ->getBoardSizeX(); j++)
            {
                if (j==0)
                {
                    MacUILib_printf("#");
                }
                
                else if (j==myGM ->getBoardSizeX())
                {
                    MacUILib_printf("#");
                }

                else if ( playerPos.pos->x == j && playerPos.pos->y == i)
                {
                    MacUILib_printf("%c", playerPos.symbol);
                }

                else if ( foodPos.pos->x == j && foodPos.pos->y == i)
                {
                    MacUILib_printf("%c", foodPos.symbol);
                }

                else 
                {
                    MacUILib_printf(" ");
                }

            } 

            MacUILib_printf("\n");
            i++;
            
        }


    }

    if (myGM->getLoseFlagStatus() == true){
        MacUILib_printf ("\nGame over: You Lose\n");
    }

    MacUILib_printf("\nscore is: %d\n", myGM->getScore());

    MacUILib_printf("\nCurrent Direction:");
    myPlayer->getDirection();

    
   
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  

    delete myPlayer;
    delete myGM;
    delete myFood;

    MacUILib_uninit();
}
