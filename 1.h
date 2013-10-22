//2nd Header File begins here.
#include <iostream>

class GameInstance{
private:
	string name; 
	Stack path; //Stack to keep track of all moves made so far.
	int turnCounter; //Counter that keeps track of number of moves made.
	int points; // Counter to keep track of points
};

class Room{
public:
	Room(string n, int numI, Items* list, string* mC, Room* mD);
	~Room();
	string name(); //getter
	void name(string n); //setter
	string shortDescript(); //getter
	void shortDescript(string newSD); //setter
	string longDescript(); //getter
	void longDescript(string newLD); //setter
	Room* destLookup(string command); //Look up destinaton based on command.

protected:
	string roomName;
	int numItems;
	Items* itemList;
	string shortDes; //Short description of room.
	string longDes; //Long description of room. for use with "look" command
	// Parallel arrays which corresponds to where a player can move.
	string* moveCommands; //What user types. 
	Room* moveDest; //Where user goes.
};

class MovingBody{ //any object in game that can be associated with a room
public:
	MovingBody(){};
	virtual ~MovingBody(){};
	virtual int performAction(){}; //return id for action.
	string name(); //getter

protected:
	string name;
};

class Player: public MovingBody{
public:
	Player(Room* l){location = l;};
	~Player();
	string currentLocation(); //getter

private:
	bool isDead; //Ends game if player is dead. 
	Item* inventory;
	Room* location;
};

class Item: public MovingBody{
public:
	Item(string n, bool e, bool p); //Edible? Perishable?
	~Item();
	virtual int eat(){return 0;};
	virtual int throw(){return 0;}; // Return -1 if subclass doesn't have implemented function, otherwise do function and return arbitrary non-negative number)
	virtual int drop(){return 0;};

protected:
	string name;
	string description; //added to description that displays after a room's description	
	int perishable; // some items may only last x number of turns. -1 for false. may not be in final game
	bool isEnvironmental;
};

class ThrowableItem: public Item{
public:
};

class EdibleItem: public ThrowableItem{
public:
};

class Weapon: public ThrowableItem{
public:
}; //this is a useless comment