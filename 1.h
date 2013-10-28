#include <iostream>
//#include "stack.h"
//#include "ListObject.h"
//#include "p2list4.h"
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
class List;
class Item{
protected:
	string itemName;
	string info; //added to description that displays after a room's description	
public:
	Item(){};
	Item(string n){name(n);};
	virtual ~Item(){};
	
	//getters
	string name(){return itemName;};
	string description(){return info;};
	
	//setters
	void name(string in){itemName=in;};
	void description(string in){info=in;};
	
	//for inheritance
	virtual bool eat(List* charInventory){charInventory=charInventory; return 0;}; //no-ops to avoid compiler errors, needs parameters so child classes properly inherit
//	virtual bool throwItem(){return 0;}; not needed in demo
	virtual bool drop(List* roomInventory, List* charInventory){charInventory=charInventory;roomInventory=roomInventory;return 0;};
	virtual bool take(List* roomInventory, List* charInventory){charInventory=charInventory;roomInventory=roomInventory;return 0;};
//	virtual bool attack(){return 0;}; not needed in demo
//	needed??	virtual bool changeStatus(string search, List* charInventory){search=search; charInventory=charInventory;return 0;};		//for status items, changes their state for interacting with each other
	virtual bool changeEnv(List* roomInventory){roomInventory=roomInventory;return 0;}; //defined for environmental items
	virtual bool observe(){return 0;}; //read a journal, look at details of object; get description.

};

struct Node{
	Item* data;
	Node* next;
	Node* prev;
};

class List{
private:
	Node* head;
public:
	List();
	~List();
	Node* getHead(){return head;};
	bool isEmpty();
	void append (Item* value);
	int find (Item* value);
	int getSize();
	void removeNth(int n);
};

class InventoryItem: public Item{
public:
	InventoryItem(){};
	InventoryItem(string in){name(in);};
	~InventoryItem(){};

	// unique inherited functions
	bool take(List* roomInventory, List* charInventory);
	bool drop(List* roomInventory, List* charInventory);
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
not in demo
class Weapon: public InventoryItem{
public:
}; 
*/

class StatusItem: public InventoryItem{ 	//these will interact with environmental items
protected:
	bool status; //this affects the appropriate environment variable
public:
	StatusItem(){};
	StatusItem(string in){name(in);};
	~StatusItem(){};
	//getter
	bool itemState(){return status;};
	//setter
	void itemState(bool in){status=in;};
};

class EnvironmentItem:public Item{
protected:
	string requirement;		//the name of the item that must be used in room to satisfy and remove object.
		
public:
	EnvironmentItem(){};
	~EnvironmentItem(){};
	//getter
	string requiredItem(){return requirement;};
	//setters
	void requiredItem(string in){requirement=in;};
	bool changeEnv(List* roomInventory); //defined for environmental items	//takes name of item that meets condition; check itemState() from item; removes itself from room if met. 
};
