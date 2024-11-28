
#include "Player.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    currentDirection = STOP;

    // more actions to be included
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
    playerPos.symbol = '*';
}


Player::~Player()
{
    // delete any heap members here
    //delete playerPos.pos;
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos; // x,y,symbol through value
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
    // PPA3 Finite State Machine logic
    switch(currentDirection)
        {
            case UP:  //implenting wraparound and matrix increase and decreasing.
                playerPos.pos->y--;
                if (playerPos.pos->y == 0)
                {
                    playerPos.pos->y = mainGameMechsRef -> getBoardSizeX()-1;
                }
                break;
                
            case DOWN:
                playerPos.pos->y++;
                if (playerPos.pos->y==mainGameMechsRef -> getBoardSizeX())
                {
                    playerPos.pos->y = 1;
                }
                break;

            case LEFT:
                playerPos.pos->x--;
                if (playerPos.pos->x==0)
                {
                    playerPos.pos->x=(mainGameMechsRef->getBoardSizeY());
                }
                break;

            case RIGHT:
                playerPos.pos->x++;
                if (playerPos.pos->x==(mainGameMechsRef->getBoardSizeY()))
                {
                    playerPos.pos->x = 1;
                }
                break;
            case STOP:
            default:
            break;
        //input = 0;
        }
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