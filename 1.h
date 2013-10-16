#include <iostream>

//1st Header File begins here.
class GameInstance{
private:
	string name;
	Stack path;
	int turnCounter;
	int points;

};

class Room{
public:
	Room();
	~Room();
	name(); //getter
	name(string n); //setter

protected:
	string name;
	int numItems;
	Items* itemList;
	string shortDes; //Short description of room.
	string longDes; //Long description of room.
	// Parallel arrays which corresponds to where a player can move.
	string* moveCommands; //What user types. 
	Room* moveDest; //Where user goes.
};

class MovingBody{
public:
	MovingObject(string n, bool e, bool p); //name, edible, perishable?
	virtual ~MovingObject(){};
	virtual performAction(){};
	name(); //getter

protected:
	string name;
	bool edible;
	bool perishable;
};

class Player: public MovingBody{
public:
	Player(Room* l){location = l;};
	~Player();
private:
	Room* location;
};
