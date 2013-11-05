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
    for (int i=0; i<numNeighbour(); i++) {
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

string Player::getDescription(string command, string object){
		string roomDesc="";
		string checker = currentLocation()->listItem()->listAllDesc();
	if((command=="LOOK"||command=="OBSERVE")&&(object=="ROOM"||object==""))
		roomDesc = currentLocation()->shortDescript() + " " + currentLocation()->longDescript();
	else{
		roomDesc = currentLocation()->shortDescript();
	}
	roomDesc += "\n\n " + checker;
	return roomDesc;
}

void Player::performAction(string verb, string noun)
{
	Item* EnvBlock = currentLocation()->listItem()->findByCommand(verb, noun);
	if(EnvBlock!=NULL && EnvBlock->currentState()==true){
		cout << "The " << EnvBlock->name() << " is in the way!\n";  
	}
    else if (verb == "TAKE")
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
		if(verb=="LOOK"&&noun=="INVENTORY"){
			string currentInventory = inventory()->listAll();
			if(currentInventory=="")
				cout << "You have nothing in your inventory\n";
			else
				cout << "You have a " << currentInventory <<" in your inventory\n"; 
		}	
		else if(noun=="ROOM" || noun==""){
			cout << "You're in "<<getDescription(verb, noun) <<endl;
			string itemsInRoom=currentLocation()->listItem()->listAll();
			if (itemsInRoom != "")
				cout <<"There is a " << itemsInRoom <<" in this room." << endl;		}
		else{
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
	}
    //move function
    else if (verb == "MOVE" || verb == "GO")
    {
        bool moved=false;
        for (int i=0; i<currentLocation()->numNeighbour(); i++) {
            if (*(currentLocation()->moveCommand()+i)==noun) {
                currentLocation(*(currentLocation()->moveDest()+i));
                moved=true;
				break;
            }
        }
        
        if (moved==false) {
            cout<< "You can not move " << noun << endl;
        }
        else
        {
            cout <<"You have moved " << noun << endl << endl;
			cout << "You're in " << getDescription(verb, noun) <<endl;
			string itemsInRoom=currentLocation()->listItem()->listAll();
			if (itemsInRoom != "")
				cout <<"There is a " << itemsInRoom <<" in this room." << endl;
			
        }

    }
    
	else if(verb=="USE"){
		Item* wanted = inventory()->findByName(noun); //this is the item we are looking for
 		if(wanted==NULL)
			cout << "You have no " << noun <<" in your inventory\n";
		else if(wanted->currentState()){
			cout << "This item cannot be used in it's current state\n";
		}
		else if(wanted->target()!=""){
			string target="";	//completely different from above statement
			bool itWorked = wanted->use(inventory(), target);
			if(itWorked)
				cout << "You used " << noun << " on " << target<<".\n";
			else
				cout << "You cannot use " << noun << " here. \n";
		}
		else{
			string target = "";
			bool itWorked = wanted->use(currentLocation()->listItem(), target);
			if(itWorked)
				cout << "You used " << noun << " on " << target<<".\n";
			else
				cout << "You cannot use " << noun << " here. \n";
		}
	}
	
	else if(verb == "HELP"){
		cout << " You must enter in a two-word command, in the format\n \nverb noun\n\n";
		cout << "If you get stuck, try looking at the room or at some of the items in your inventory.\n\n";
		cout << "If you forget the items you have with you, look at your inventory to see them.\n\nGood Luck!\n";
	}
	
    else
    {
        cout << "I'm sorry, I don't understand that." << endl;
    }
}
