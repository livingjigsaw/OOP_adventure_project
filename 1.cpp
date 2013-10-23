#include <iostream>
#include "1.h"

Room(string n, int numI, list* nodeItem, string SD, string LD, string* mC, Room** mD, int numN){
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
void Room::numNeighbour(int x)//setter
{
    numNeighbours=x;
}

int Room::numberItem()
{
    return numItems;
}
void Room::numberItem(int x)
{
    numItems=x;
}
 
list* Room::listItem()
{
    return list;
}

void Room::listItem(list* n)
{
    nodeItem=n;
}

string* Room::moveCommand()
{
    return moveCommands;
}

void Room::moveCommand(string* mC)
{
    moveCommands=mC;
}

Room** Room::moveDest()
{
    return moveDests;
}

void Room::moveDest(Room** mD)
{
    moveDests=mD;
}


Room** Room::destLookup(string command)
{
    for (i=numNeighbours; i>0; i--) {
        if (command==moveCommands[i]) {
            return moveDests[i];
        }
    }
}