#include <iostream>
#include "1.h"


//operators
template<class T>
bool operator ==(Tuples<T> a, T b){
    if (a.size()!=b.size()) {
        return false;
    }
    for (int i=0; i<a.size(); i++) {
        if a[i] != b[i]
            return false;
    }
    return true;
}

template<class T>
bool operator !=(Tuples<T> a, T b){
    for (int i=0; i<a.size(); i++) {
        if (a[i]==b[i])
            return true;
    }
    return false;
}

//Room functions begin here.
Room::Room(string n, int numI, list* nodeItem, string SD, string LD, string* mC, Room** mD, int numN){
    roomName=n;
    numItems=numI;
    itemList = nodeItem;
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
    return numNeighbours;
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

//Player functions begin here.
Player::Player(Room* l)
{
    location = l;
    isDead = false;
}

Room* Player::currentLocation()
{
    return location;
}

void Player::currentLocation(Room* newLocation)
{
    location = newLocation;
}

void Player::performAction(string verb, string noun)
{
    if (verb == "TAKE")
    {
        bool found = false;
		bool status = false;
        Node<T>* walker = (currentLocation -> itemList) -> head;    
        for (int i = 0; i < getSize((currentLocation) -> itemList); i++)
        {
            if (((walker -> data) -> name()) == noun)
            {
                found = true;
                status = (walker -> data) -> take();
                /*
                append (inventory, (walker -> data)); // Adds item to player inventory.
                removeNth ((currentLocation -> itemList), i); // Removes item from room item list.
                */
            }
        }
        walker = NULL;
        if (found){
			if (status)
				cout << "You have taken " << noun << "." << endl;
			else
				cout << "You cannot do that with that object\n";
        }
		else 
            cout << "There is no " << noun << " here." << endl;
    }
    
    // drop function
    
    if (verb == "DROP")
    {
        bool found = false;
		bool status = false;
        Node<T>* walker = charInventory -> head;    
        for (int i = 0; i < getSize(charInventory); i++)
        {
            if (((walker -> data) -> name()) == noun)
            {
                found = true;
                status = (walker -> data) -> drop();
            }
        }
        walker = NULL;
        if (found){
			if (status)
				cout << "You have drop " << noun << "." << endl;
			else
				cout << "You cannot do that with that object\n";
        }
		else 
            cout << "You don't have" << noun << " here." << endl;
    }

}