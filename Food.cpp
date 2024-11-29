#include "Food.h"
#include "MacUILib.h"
#include "string.h"
#include <stdlib.h>
#include <time.h>



Food::Food()
{
    foodPos.pos->x = 0;
    foodPos.pos-> y = 0;
    foodPos.symbol ='\0';

}


Food::~Food()
{
    // delete any heap members here
    // no key word new in constructor leave empty for now
}

void Food::generateFood(objPosArrayList* blockOff)
{
    srand(time(NULL));
    char random_ascii;
    int rand_idx;
    bool overlaps=false;
    objPos newFoodPos;

    char ascii_chars[94];
    

    // initializing ascii_char
   int j=0;
    for (int i=33; i <= 126; i++){
        if (i != ' ' && i != '#' && i!= '@'){
            ascii_chars[j]= (char) i;
            //MacUILib_printf("%c", ascii_chars[j]);
            j++;
        } 
    }

    ascii_chars[j] = '\0';
    
    do{
        foodPos.pos->x = (rand() % 29+1);
        foodPos.pos->y = (rand() % 14+1);

        int playerSize = blockOff->getSize();
        // the other 3 chars selected from ascii_chars
        for( int i=0; i<playerSize; i++){
            objPos listSeg = blockOff->getElement(i);
            if( listSeg.pos->x == newFoodPos.pos->x && listSeg.pos->y == newFoodPos.pos->y)
            {
                overlaps = true;
            }
        }
    } while (overlaps);

    //selecting random index of ascii_chars
    rand_idx = rand() % strlen(ascii_chars);
    //assigning value at index to random_ascii
    foodPos.symbol = ascii_chars[rand_idx]; 
    /* while (blockOff->getHeadElement().pos->x == foodPos.pos->x || blockOff->getHeadElement().pos->y == foodPos.pos->y){
        foodPos.pos->x = (rand() % 30+1);
        foodPos.pos->y = (rand() % 15+1);
    } */
    
    
}


objPos Food::getFoodPos() const
{
    // return the reference to the playerPos arrray list
    return foodPos;
}
