#include "1.h"
class Room{
public:
	Room(string n, int numI, List* nodeItem, string SD, string LD, string* mC, Room** mD, int numN);
	~Room(){};
	
	string name()const{return roomName;}; //getter
	string shortDescript() const{return shortDes;}; //getter
	string longDescript()const{return longDes;}; //getter
	int numItem() const{return numItems;}; //getter
	int numNeighbour() const{return numNeighbours;}; //getter
	List* listItem()const{return itemList;}; //getter
	string* moveCommand()const{return moveCommands;}; //getter
	Room** moveDest()const{return moveDests;}; //getter
	
	void name(string n){roomName=n;}; //setter
	void shortDescript(string newSD){shortDes=newSD;}; //setter
	void longDescript(string newLD){longDes=newLD;}; //setter
	void numItem(int x){numItems=x;};//setter
    void numNeighbour(int x){numNeighbours=x;};//setter
    void  listItem(List* n){itemList=n;}; //setter
    void  moveCommand(string* n){moveCommands=n;}; //setter
    void  moveDest(Room** mD){moveDests = mD;}; //setter
    
	Room* destLookup(string command); //Look up destinaton based on command.

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
	~Player(){};
	Room* currentLocation(){return location;}; //getters
	List* inventory(){return playerItems;};
	
	void currentLocation(Room* newLocation){location = newLocation;}; //setters
	void inventory(List* in){playerItems=in;};
	
	void performAction(string verb, string noun);

private:
	bool isDead; //Ends game if player is dead. 
	List* playerItems;
	Room* location;
};
