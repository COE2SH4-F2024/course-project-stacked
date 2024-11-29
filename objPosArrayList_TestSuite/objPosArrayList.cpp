#include <iostream>
#include "objPosArrayList.h"

using namespace std;

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
    for(int i=0;i<listSize;i++)
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

        for(int i=0;i<listSize;i++)
        {
            //this->aList[i] = a.aList[i];
            aList[i] = a.aList[i];
        }
    }

    return *this;
}

int objPosArrayList::getSize() const
{
    return listSize;
}
void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize == arrayCapacity) {
        cout << "Array capacity exceeded" << endl;
        return;
    }


    for(int i=listSize;i>0;--i)
    {
        aList[i] = aList[i-1];
    }

    aList[0] = thisPos;
    ++listSize;
}
void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize == arrayCapacity) {
        cout << "Array capacity exceeded" << endl;
        return;
    }

    aList[listSize] = thisPos;
    ++listSize;
}
void objPosArrayList::removeHead()
{
    if (listSize == 0) {
        cout << "list empty" << endl;
        return;
    }

    for(int i=0;i<listSize-1;++i)
    {
        aList[i] = aList[i+1];
    }
    --listSize;
}
void objPosArrayList::removeTail()
{
    if (listSize == 0) {
        cout << "List is empty" << endl;
        return;
    }

    listSize--; // Lazy delete
}

//Getters

objPos objPosArrayList::getHeadElement() const
{
    if (listSize == 0) {
        cout << "List is empty" << endl;
        return objPos(); // Assuming objPos has a default constructor
    }
    
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    if (listSize == 0) {
        cout << "List is empty" << endl;
        return objPos(); // Assuming objPos has a default constructor
    }   
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index)
{
    
    if (index < 0 || index >= listSize) {
        cout << "Index out of bounds" << endl;
        return objPos(); // Assuming objPos has a default constructor
    }
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