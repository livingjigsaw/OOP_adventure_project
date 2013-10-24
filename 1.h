#include <iostream>
#include "stack.h"
#include "p2list4.h"
using namespace std;

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
	Room(string n, int numI, List* nodeItem, string SD, string LD, string* mC, Room** mD, int numN;);
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
	void performAction(string verb, string noun);

private:
	bool isDead; //Ends game if player is dead. 
	List* inventory;
	Room* location;
};

class Item{
protected:
	string itemName;
	string info; //added to description that displays after a room's description	
public:
	Item(){};
	Item(string n);
	~Item(){};
	
	//getters
	string name(){return itemName;};
	string description(){return info;};
	
	//setters
	void name(string in){itemName=in;};
	void description(string in){info=in;};
	
	//for inheritance
	virtual bool eat(List* charInventory){charInventory=roomInventory; return 0;}; //no-ops to avoid compiler errors, needs parameters so child classes properly inherit
//	virtual bool throwItem(){return 0;}; not needed in demo
	virtual bool drop(List* roomInventory, List* charInventory){charInventory=charInventory;roomInventory=roomInventory;return 0;};
	virtual bool take(List* roomInventory, List* charInventory){charInventory=charInventory;roomInventory=roomInventory;return 0;};
//	virtual bool attack(){return 0;}; not needed in demo
//	needed??	virtual bool changeStatus(string search, List* charInventory){search=search; charInventory=charInventory;return 0;};		//for status items, changes their state for interacting with each other
	virtual bool changeEnv(List* roomInventory){roomInventory=roomInventory;return 0;}; //defined for environmental items
	virtual bool observe(ostream lhs){lhs=lhs;return 0;}; //read a journal, look at details of object; get description.

};

class InventoryItem: public Item{
public:
	InventoryItem(){};
	~InventoryItem(){};

	// unique inherited functions
	bool take(List* roomInventory, List* charInventory);
	bool drop(List* roomInventory, List* charInventory);
	bool observe(List* charInventory);
	
};

class EdibleItem: public InventoryItem{
public:
	EdibleItem(){};
	~EdibleItem(){};
	
	bool eat(List* charInventory);
};

/* not in demo
class Weapon: public InventoryItem{
public:
}; 
*/

class StatusItem: public InventoryItem{ 	//these will interact with environmental items
protected:
	bool status; //this affects the appropriate environment variable
public:
	//getter
	bool itemState(){return status;};
	//setter
	void itemState(bool in){status=in;};
}

class EnvironmentItem:public Item{
	protected:
		string requirement;		//the name of the item that must be used in room to satisfy and remove object.
		
	public:
		//getter
		string requiredItem(){return requirement;};
		//setters
		void requiredItem(string in){requirement=in;};
		bool changeEnv(List* roomInventory); //defined for environmental items	//takes name of item that meets condition; check itemState() from item; removes itself from room if met. 
};
