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
	virtual bool eat(List<Item*>* charInventory){charInventory=charInventory; return 0;}; //no-ops to avoid compiler errors, needs parameters so child classes properly inherit
//	virtual bool throwItem(){return 0;}; not needed in demo
	virtual bool drop(List<Item*>* roomInventory, List<Item*>* charInventory){charInventory=charInventory;roomInventory=roomInventory;return 0;};
	virtual bool take(List<Item*>* roomInventory, List<Item*>* charInventory){charInventory=charInventory;roomInventory=roomInventory;return 0;};
//	virtual bool attack(){return 0;}; not needed in demo
//	needed??	virtual bool changeStatus(string search, List* charInventory){search=search; charInventory=charInventory;return 0;};		//for status items, changes their state for interacting with each other
	virtual bool changeEnv(List<Item*>* roomInventory){roomInventory=roomInventory;return 0;}; //defined for environmental items
	virtual bool observe(){return 0;}; //read a journal, look at details of object; get description.

};

class InventoryItem: public Item{
public:
	InventoryItem(string in){name(in);};
	~InventoryItem(){};

	// unique inherited functions
	bool take(List<Item*>* roomInventory, List<Item*>* charInventory);
	bool drop(List<Item*>* roomInventory, List<Item*>* charInventory);
	bool observe();
	
};
/*
class EdibleItem: public InventoryItem{
public:
	EdibleItem(){};
	~EdibleItem(){};
	
	bool eat(List<Item*>* charInventory);
};
*?
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
};

class EnvironmentItem:public Item{
	protected:
		string requirement;		//the name of the item that must be used in room to satisfy and remove object.
		
	public:
		//getter
		string requiredItem(){return requirement;};
		//setters
		void requiredItem(string in){requirement=in;};
		bool changeEnv(List<Item*>* roomInventory); //defined for environmental items	//takes name of item that meets condition; check itemState() from item; removes itself from room if met. 
};


class Room{
public:
	Room(string n, int numI, List<Item*>* nodeItem, string SD, string LD, string* mC, Room** mD, int numN);
	~Room(){};
	
	string name()const{return roomName;}; //getter
	string shortDescript() const{return shortDes;}; //getter
	string longDescript()const{return longDes;}; //getter
	int numItem() const{return numItems;}; //getter
	int numNeighbour() const{return numNeighbours;}; //getter
	List<Item*>* listItem()const{return itemList;}; //getter
	string* moveCommand()const{return moveCommands;}; //getter
	Room** moveDest()const{return moveDests;}; //getter
	
	void name(string n){roomName=n;}; //setter
	void shortDescript(string newSD){shortDes=newSD;}; //setter
	void longDescript(string newLD){longDes=newLD;}; //setter
	void numItem(int x){numItems=x;};//setter
    void numNeighbour(int x){numNeighbours=x;};//setter
    void  listItem(List<Item*>* n){itemList=n;}; //setter
    void  moveCommand(string* n){moveCommands=n;}; //setter
    void  moveDest(Room** mD){moveDests = mD;}; //setter
    
	Room* destLookup(string command); //Look up destinaton based on command.

protected:
	string roomName;
	int numItems;
    int numNeighbours;
	List<Item*>* itemList;
	string shortDes; //Short description of room.
	string longDes; //Long description of room. for use with "look" command
	// Parallel arrays which corresponds to where a player can move.
	string* moveCommands; //What user types. 
	Room** moveDests; //Where user goes.
};

class Player{
public:
	Player(Room* l);
	~Player(){};
	Room* currentLocation(){return location;}; //getters
	List<Item*>* inventory(){return playerItems;};
	
	void currentLocation(Room* newLocation){location = newLocation;}; //setters
	void inventory(List<Item*>* in){playerItems=in;};
	
	void performAction(string verb, string noun);

private:
	bool isDead; //Ends game if player is dead. 
	List<Item*>* playerItems;
	Room* location;
};

