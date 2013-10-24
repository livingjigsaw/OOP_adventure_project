#include <iostream>
#include "stack.h"

/*
class GameInstance{
private:
	string name; 
	Stack path; //Stack to keep track of all moves made so far.
	int turnCounter; //Counter that keeps track of number of moves made.
	int points; // Counter to keep track of points
};
*/

class Room{
public:
	Room(string n, int numI, list* nodeItem, string SD, string LD, string* mC, Room** mD, int numN;);
	~Room();
	string name(); //getter
	void name(string n); //setter
	string shortDescript(); //getter
	void shortDescript(string newSD); //setter
	string longDescript(); //getter
	void longDescript(string newLD); //setter
    int numI(); //getter
    void numberItem(int x);//setter
    int numN(); //getter
    void numNeighbour(int x);//setter
    List* listItem(); //getter
    void  listItem(list* n); //setter
    string* moveCommand(); //getter
    void  moveCommand(list* n); //setter
    Room** moveDest(); //getter
    void  moveDest(Room** mD); //setter
    
	Room** destLookup(string command); //Look up destinaton based on command.

protected:
	string roomName;
	int numItems;
    int numNeighbours;
	List* itemList;
	string shortDes; //Short description of room.
	string longDes; //Long description of room. for use with "look" command
	// Parallel arrays which corresponds to where a player can move.
	string* moveCommands; //What user types. 
	Room** moveDests; //Where user goes.
};

class Player{
public:
	Player(Room* l);
	~Player();
	Room* currentLocation(); //getter
	void currentLocation(Room* newLocation); //setter

private:
	bool isDead; //Ends game if player is dead. 
	List* inventory;
	Room* location;
};

class Item{
public:
	Item(string n);
	~Item();
	virtual bool eat(){return 0;};
	virtual bool throwItem(){return 0;}; // Return 0 if subclass doesn't have implemented function for try/catch statements)
	virtual bool drop(){return 0;};
	virtual bool attack(){return 0;};
	virtual bool changeStatus(){return 0;};		//for environment/status items, changes their state for interacting with each other
	virtual bool observe(){return 0;}; //read a journal, look at details of object; get description.
	virtual bool changeStatus(){return 0;}; //defined for environmental and status items
	virtual bool take(){return 0;};
protected:
	string name;
	string description; //added to description that displays after a room's description	

};

class InventoryItem: public Item{
protected:
	
public:
	
};

class EdibleItem: public InventoryItem{
public:
};

/* not in demo
class Weapon: public InventoryItem{
public:
}; 
*/

class StatusItem: public InventoryItem{ 	//these will interact with environmental items
protected:
	
public:

}

class EnvironmentItem:public Item{
	protected:
		string requirement;		//the name of the item that must be used in room to satisfy and remove object.
		
	public:
		isConditionMet(string name);		//takes name of item that meets condition; items that meet environmental conditions will always be a certain type that have a "condition" bool that his function can access
};
