//1st Header File - Existing Stack Implementation.
#include <cstddef>
#include <cstring>

template <class T>
struct Stack {
   T*  data;	// array of values
   int size;	// size of array
   int top;	// index of value currently at top of Stack
};

template <class T>
void initialize(Stack<T>&s)
{
	s.size = 2;
	s.data = new T [s.size];
	s.top = 0;
}

template <class T>
void destroy(Stack<T>&s)
{
	s.top = 0;
	delete []s.data;
	s.data = NULL;
}

template <class T>
bool isEmpty(Stack<T> s)
{
	return (s.top == 0);
}

template <class T>
void push(Stack<T>&s,T x)
{
	if (s.top == s.size)
	{
		s.size *= 2;
		T* tmp = new T[s.size];
		for (int i = 0; i < s.size/2; i++)
			tmp[i] = s.data[i];
		delete []s.data;
		s.data = tmp;
		tmp = NULL;
	}
	s.data[s.top] = x;
	s.top ++;
}

template <class T>
T    pop(Stack<T>&s)
{
	s.top --;
	return s.data[s.top];
}

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
	MovingObject(){};
	virtual ~MovingObject(){};
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
	int performAction();
	void checkKeyword(string s); //calls performAction() if keywords are similar.

private:
	string* keywords; //array of keywords associated with the object.
	string description; //added to description that displays after a room's description	
	int perishable; // some items may only last x number of turns. -1 for false. may not be in final game
};