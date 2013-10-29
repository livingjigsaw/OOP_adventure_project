#include <iostream>
#include "room.h"
//Room functions begin here.
Room::Room(string n, int numI, List* nodeItem, string SD, string LD, string* mC, Room** mD, int numN){
    roomName=n;
    numItems=numI;
    itemList = nodeItem;
    shortDes=SD;
    longDes=LD;
    moveCommands=mC;
    moveDests=mD;
    numNeighbours=numN;
}


Room* Room::destLookup(string command)
{
    for (int i=numNeighbours; i>0; i--) {
        if (command==moveCommands[i]) {
            return moveDests[i];
        }
    }
	return NULL;
}

//Player functions begin here.
Player::Player(Room* l)
{
    location = l;
    isDead = false;
	List* start=new List;
	inventory(start);
}


void Player::performAction(string verb, string noun)
{
    if (verb == "TAKE")
    {
        bool found = false;
		bool status = false;
        Node* walker = (currentLocation() -> listItem()) -> getHead();    
        for (int i = 0; i < ((currentLocation()) -> listItem()) -> getSize(); i++)
        {
            if (((walker -> data)->name()) == noun)
            {
                found = true;
                status = (walker -> data)->take(currentLocation()->listItem(),inventory());
                int newNum = currentLocation() -> numItem();
                newNum --;
                currentLocation() -> numItem(newNum);
            }
            walker = walker -> next;
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
    
    else if (verb == "DROP")
    {
        bool found = false;
		bool status = false;
        Node* walker = inventory() -> getHead();    
        for (int i = 0; i < inventory() -> getSize(); i++)
        {
            if (((walker -> data)->name()) == noun)
            {
                found = true;
                status = (walker -> data)->drop(currentLocation()->listItem(),inventory());
                int newNum = currentLocation() -> numItem();
                newNum++;
                currentLocation() -> numItem(newNum);
            }
            walker = walker -> next;
        }
        walker = NULL;
        if (found){
			if (status)
				cout << "You have dropped " << noun << "." << endl;
			else
				cout << "You cannot do that with that object\n";
        }
		else 
            cout << "You don't have" << noun << " here." << endl;
    }

    // observe function

    else if (verb == "OBSERVE" || verb == "READ" || verb == "LOOK")
    {
        bool found = false;
        bool status = false;
        Node* walker = inventory() -> getHead();    
        for (int i = 0; i < inventory() -> getSize(); i++)
        {
            if (((walker -> data)->name()) == noun)
            {
                found = true;
                status = (walker -> data)->observe();
                break;
            }
            walker = walker -> next;
        }
        walker = NULL;
        if (found){
            if (status)
                cout << endl;
        }
        else 
            cout << "You don't have a " << noun << " with you." << endl; 
    }
  
    //move function
    else if (verb == "MOVE" || verb == "GO")
    {
        bool moved=false;
        for (int i=0; i<currentLocation()->numNeighbour(); i++) {
            if (*(currentLocation()->moveCommand()+i)==noun) {
                currentLocation(*(currentLocation()->moveDest()+i));
                moved=true;
            }
        }
        
        if (moved==false) {
            cout<< "You can not move " << noun << endl;
        }
        else
        {
            cout <<"You have moved " << noun << endl << endl;
            cout << currentLocation() -> longDescript() << endl;
        }

    }
    
    else
    {
        cout << "I'm sorry, I don't understand that." << endl;
    }
}
