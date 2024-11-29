
#include "Player.h"
#include "MacUILib.h"
#include "objPosArrayList.h"
#include "Food.h"


Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef;
    theFood = foodRef;
    currentDirection = STOP;
    

    playerPosList = new objPosArrayList();
    //objPos headPos(thisGMRef->getBoardSizeX() / 2, thisGMRef->getBoardSizeY() / 2, '*');
    //playerPosList->insertHead(headPos);
    objPos headPos(thisGMRef->getBoardSizeX() / 2, thisGMRef->getBoardSizeY() / 2, '*');
    playerPosList->insertHead(headPos);
    
    // more actions to be included
    //playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
   // playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
    //playerPos.symbol = '*';
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList; // x,y,symbol through value
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    char input = mainGameMechsRef->getInput();
    //mainGameMechsRef->clearInput();
    if (input !=0){
    switch(input)
    {                      
        case 'w': //using enumeration to check direction to keep FSM logic 
        case 'W':
            if (currentDirection==LEFT || currentDirection==RIGHT || currentDirection == STOP)
            {
                currentDirection=UP;
            }
            break;

        case 's':
        case 'S':
            if (currentDirection==LEFT || currentDirection==RIGHT ||currentDirection == STOP)
            {
                currentDirection=DOWN;
            }
            break;
        case 'a':
        case 'A':
            if (currentDirection==UP || currentDirection == DOWN || currentDirection == STOP)
            {
                currentDirection=LEFT;
            }
            break;

        case 'd':
        case 'D':
            if(currentDirection==UP || currentDirection==DOWN || currentDirection == STOP)
            {
                currentDirection =RIGHT;
            }
            break;

        case STOP:
        default:
            break;
    } 
    }     
}

void Player::movePlayer()
{
    //char input = mainGameMechsRef->getInput();
    objPos currentPos = playerPosList->getHeadElement();

    objPos newPos = currentPos;

    // PPA3 Finite State Machine logic
    switch(currentDirection)
    
        {
            case UP:  //implenting wraparound and matrix increase and decreasing.
                newPos.pos->y--;
                if (newPos.pos->y == 0)
                {
                    newPos.pos->y = mainGameMechsRef -> getBoardSizeY()-1;
                }
                break;
                
            case DOWN:
                newPos.pos->y++;
                if (newPos.pos->y==mainGameMechsRef -> getBoardSizeY())
                {
                    newPos.pos->y = 1;
                }
                break;

            case LEFT:
                newPos.pos->x--;
                if (newPos.pos->x==0)
                {
                    newPos.pos->x=(mainGameMechsRef->getBoardSizeX()-1);
                }
                break;

            case RIGHT:
                newPos.pos->x++;
                if (newPos.pos->x==(mainGameMechsRef->getBoardSizeX()))
                {
                    newPos.pos->x = 1;
                }
                break;
            case STOP:
            default:
                break;
        //input = 0;
        }


    // Check food consume
    if (checkFoodConsumption()){

        increasePlayerLength();
        theFood->generateFood(playerPosList);
        mainGameMechsRef ->incrementScore();


    }
    // Add new head position and remove the tail
    playerPosList->insertHead(newPos);
    //playerPosList->removeTail();
    playerPosList->removeTail();
    
    checkSelfCollision();
}
/* #include "Player.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    currentDirection = STOP;

    // more actions to be included
    playerPos.pos->x = mainGameMechsRef -> getBoardSizeX()/2;
    playerPos.pos->y = mainGameMechsRef -> getBoardSizeY()/2;
    playerPos.symbol = '@';
}


Player::~Player()
{
    // delete any heap members here
    // no key word new in constructor leave empty for now
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef -> getInput();
        // PPA3 input processing logic 

    if(input != 0)  // input != 0 if not null character
    {
        switch(input)
            {                      
                
                // Add more key processing here
                case 'w':
                    if (currentDirection == LEFT || currentDirection == RIGHT || currentDirection == STOP)
                        currentDirection = UP;
                    break;

                case 'a':
                    if (currentDirection == UP || currentDirection == DOWN  || currentDirection == STOP)
                        currentDirection = LEFT;
                    break;

                case 's':
                    if (currentDirection == LEFT || currentDirection == RIGHT  || currentDirection == STOP)
                        currentDirection = DOWN;
                    break;

                case 'd':
                    if (currentDirection == UP || currentDirection == DOWN  || currentDirection == STOP)
                        currentDirection = RIGHT;
                    break;

                default:
                    break;
            }
    }   

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    

        switch (currentDirection)
        {
            case UP:
                playerPos.pos->y -=  1;
            break;

            case DOWN:
                playerPos.pos->y+= 1;
            break;

            case RIGHT:
                playerPos.pos->x += 1;
            break;

            case LEFT:
                playerPos.pos->x-= 1;
            break;

            default:
                break;

    
        }
    
    if (playerPos.pos->x== 0)
        playerPos.pos->x = mainGameMechsRef -> getBoardSizeX() - 1;
    else if (playerPos.pos->x == mainGameMechsRef -> getBoardSizeX())
        playerPos.pos->x = 1;

    
    if (playerPos.pos->y == 0)
        playerPos.pos->y = mainGameMechsRef -> getBoardSizeY() - 1;
    else if (playerPos.pos->y == mainGameMechsRef -> getBoardSizeY())
        playerPos.pos->y = 1;
    

} */

// More methods to be added
char Player::getDirection()
{
    switch (currentDirection)
    {
        case UP:
            MacUILib_printf("UP\n");
            break;
        case DOWN:
            MacUILib_printf("DOWN\n");
            break;
        case LEFT:
            MacUILib_printf("LEFT\n");
            break;
        case RIGHT:
            MacUILib_printf("RIGHT\n");
            break;
        default:
            MacUILib_printf("UNKNOWN\n");
            break;
    };
} 

bool Player:: checkFoodConsumption ()
{
    objPos headPos = playerPosList->getHeadElement();
    objPos foodPos = theFood->getFoodPos();

    if (headPos.pos-> x == foodPos.pos->x && headPos.pos->y == foodPos.pos->y){
        return true;
    }
    return false;
}
void Player:: increasePlayerLength ()
{
   objPos lastPos = playerPosList->getTailElement();

   playerPosList->insertTail(lastPos);
   
}

bool Player:: checkSelfCollision ()
{
    for (int i=1; i<playerPosList->getSize(); i++)
    {
        objPos headPos = playerPosList->getHeadElement();
        objPos listSeg = playerPosList->getElement(i);
        if(headPos.pos->x == listSeg.pos->x && headPos.pos->y == listSeg.pos->y)
        {
            mainGameMechsRef -> setLoseFlag();
            mainGameMechsRef -> setExitTrue();
        }
    }
}