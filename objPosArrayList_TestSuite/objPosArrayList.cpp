#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList() // default
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[ARRAY_MAX_CAP];
}
objPosArrayList::~objPosArrayList() // destructor
{
    delete[] aList;
}
objPosArrayList::objPosArrayList(const objPosArrayList &a) // copy
{
    listSize = a.listSize;
    arrayCapacity = a.arrayCapacity;

    aList = new objPos[arrayCapacity];
    for(int i=0;i<arrayCapacity;i++)
    {
        aList[i] = a.aList[i];
    }
}
objPosArrayList& objPosArrayList::operator = (const objPosArrayList &a) // copy assigment
{
    if (this != &a)
    {
        delete[] aList;
        listSize = a.listSize;
        arrayCapacity = a.arrayCapacity;

        aList = new objPos[arrayCapacity];

        for(int i=0;i<arrayCapacity;i++)
        {
            this->aList[i] = a.aList[i];
        }
    }
}

int objPosArrayList::getSize()
{
    return listSize;
}
void objPosArrayList::insertHead(objPos thisPos)
{
    // if(listSize == arrayCapacity)
    // {
    //     return;
    // }
    for(int i=listSize;i>0;i--)
    {
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;
    listSize++;
}
void objPosArrayList::insertTail(objPos thisPos)
{
    // if(listSize == arrayCapacity)
    // {
    //     return; //exit flag winning steatement
    // }
    aList[listSize] = thisPos;
    listSize++;
}
void objPosArrayList::removeHead()
{
    // if(listSize == 0)
    // {
    //     return;
    // }
    for(int i=0;i<listSize-1;i++)
    {
        aList[i] = aList[i+1];
    }
    listSize--;
}
void objPosArrayList::removeTail()
{
    // if(listSize == 0)
    // {
    //     return;
    // }
    listSize--; // Lazy delete
}

//Getters

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[-1];
}

objPos objPosArrayList::getElement(int index)
{
    return aList[index];
}
/* #include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos;
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;

}

objPosArrayList::~objPosArrayList()
{

}

int objPosArrayList::getSize() const
{

}

void objPosArrayList::insertHead(objPos thisPos)
{
    
}

void objPosArrayList::insertTail(objPos thisPos)
{
    
}

void objPosArrayList::removeHead()
{
    
}

void objPosArrayList::removeTail()
{
    
}

objPos objPosArrayList::getHeadElement() const
{
    
}

objPos objPosArrayList::getTailElement() const
{
    
}

objPos objPosArrayList::getElement(int index) const
{
    
} */