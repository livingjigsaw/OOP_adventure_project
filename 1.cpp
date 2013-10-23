#include <iostream>
#include "1.h"

Room(string n, int numI, Items* list, string SD, string LD, string* mC, Room** mD, int numN){
    roomName=n;
    numItems=numI;
    list=itemList;
    shortDes=SD;
    longDes=LD;
    moveCommands=mC;
    moveDest=mD;
    numNeighbours=numN;
}
string Room::name() const
{
    return roomName;
}
void Room::name(string n)
{
    roomName=n;
}

string Room::shortDescript() const //getter
{
    return shortDes;
}
void Room::shortDescript(string newSD) //setter
{
    shortDes=newSD;
}

string Room::longDescript() const
{
    return longDes;
}
void Room::longDescript(string newLD)
{
    longDes=newLD;
}

int Room::numNeighbour() //getter
{
    return numNeighbours
}
void Room::numberItem(int x)//setter
{
    numNeighbours=x;
}

int Room::numberItem()
{
    return numItems;
}
void numberItem(int x)
{
    numItems=x;
}

Room** destLookup(string command)
{
    for (i=numNeighbours; i>0; i--) {
        if (command==mC[i]) {
            return mD[i];
        }
    }
}