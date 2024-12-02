#include "GameMechs.h"
#include "MacUILib.h"
#include "Food.h"

GameMechs::GameMechs()
{
    input=0;
    exitFlag= false;
    loseFlag = false;
    score = 0;

    boardSizeX = 30;
    boardSizeY = 15;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input=0;
    exitFlag= false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // nothing on heap so costructor can stay empty for now
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    
void GameMechs:: collectAsyncInput(Food* myFood, objPosArrayList* blockOff)
{
    if (MacUILib_hasChar()) {

        input = MacUILib_getChar();
    }
    if (input == ' ') 
    { // exit
        setExitTrue();
    }

    /* //debug score case
    if(input == 'i')
    {
        incrementScore();
    }
    //debug lose flag
    if(input == 'l')
    {
        setLoseFlag();
    }*/

    /* //debug clear and new food
    if (input == 'c')
    {
        myFood-> generateFood(blockOff);
    }  */
} 
char GameMechs::getInput()
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore(int value) // so can be incremented more than one or just one
{
    score+= value;
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
    MacUILib_Delay(1000000);
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
    
    if (getLoseFlagStatus() == true){
        MacUILib_printf ("\n*****Game over: You Lose*****\n");
        MacUILib_Delay(1000000);
    }
}

void GameMechs::setInput(char this_input)
{
    if (MacUILib_hasChar()) {

        input = this_input;
    }
}

void GameMechs::clearInput()
{
    input = 0;
}