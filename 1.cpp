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
    numNeighbour=numN;
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

string longDescript() const
{
    return longDes;
}
void longDescript(string newLD)
{
    longDes=newLD;
}

Room** destLookup(string command)
{
    for (i=numNeighbour; i>0; i--) {
        if (command==mC[i]) {
            return mD[i];
        }
    }
}