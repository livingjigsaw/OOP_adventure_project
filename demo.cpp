#include <iostream>
#include <string>
#include <sstream>
#include "room.h"
using namespace std;

void toUpper(string& in){
	int i=0;
	char c;
	while (in[i]){
		c=in[i];
		c=toupper(c);
		in[i]=c;
		i++;
	}
}


int main(){
	cout << "debug1"<<endl;
	InventoryItem Journal("JOURNAL");
	Journal.description("A small notebook with writing in it. There are some references to cakes and lies.");
	cout << "debug2\n";
	InventoryItem PocketKnife("POCKETKNIFE");
	InventoryItem Clock("ALARMCLOCK");
	InventoryItem Painting("PAINTING");
//	InventoryItem Hatch("Hatch");
	InventoryItem Flashlight("FLASHLIGHT");
	//Item Darkness("Darkness");
//	Item GeneratorSwitch("GeneratorSwitch");
//	Item OrbButton("OrbButton");
//	Item Orb("Orb");
		cout << "debug3\n";
	List firstRList;// First room's item list.
		cout << "debug4\n"; //*********current final success**********
//		initialize(firstRList); //herpaderp the list has no constructor
	firstRList.append((Item*)&Journal);
	cout << "debug5\n";
	firstRList.append((Item*)&PocketKnife);
	cout << "debug6\n";
	firstRList.append((Item*)&Clock);
	cout << "debug7\n";
	firstRList.append((Item*)&Painting);
	cout << "debug8\n";
	string* firstRMC = new string [1]; // First room's move command.
	Room** firstRMD =new Room*[1]; firstRMD[0]=NULL; // First room's move destination. URGENT! THIS ONLY WORKS AFTER THE SECOND ROOM HAS BEEN CONSTRUCTED.
	cout<<"debug9\n";
   string n="Firstroom";
    string SD="A small, generic room with basic living necessities. There is one door to the north.";
    string LD="You are on a stiff bed in a small, generic room with basic living necessities. The room seems old, partially ruined. There is one door, in an arbitrary direction that will be designated as north.";
	Room FirstRoom(n, 3, &firstRList ,SD ,LD, firstRMC,firstRMD, 1); //Constructing the first room.
	cout<<"debug10\n";
	Player Player1(&FirstRoom);
	cout<<"debug11\n";
	char check1;
	bool gameOver = false;
	cout << "Welcome to [WIP] Adventure! Do you need instructions? (Y/N)" << endl;
	cin >> check1;
	if (check1 == 'Y' || check1 == 'y')
	{
		cout << "You navigate this game purely through text instructions." << endl;
		cout << "When prompted, please insert what you wish your character to do using commands of not more than two words (And of the form 'verb + noun')." << endl;
		cout << "If stuck, type 'Help' for some hints." << endl;
		cout << endl;
	}
	cout << "You wake up. You are on a stiff bed in a small, generic room with basic living necessities." << endl;
	cout << "The room seems old, partially ruined." << endl;
	cout << "There is one door, in an arbitrary direction that will be designated as north." << endl;
	cout << "There is a clock, a painting, a pocketknife, and a notebook in the room." << endl;
	while (!gameOver)
	{
		//File input starts here.
		string row;
		string verb = "";
		string noun = "";
		getline (cin, row);
		stringstream ss (row);
		ss >> verb;
		ss >> noun;
		toUpper(verb);
		toUpper(noun);
		if (noun == "")
		{
			noun = verb;
			verb = "";
		}
		if (noun == "QUIT")
			break;
		if (ss.rdbuf()->in_avail() != 0) // Check if there're any words left in buffer, if there are, then user input was more than 2 words.
		{
			cout << "Please only enter up to 2 words only." << endl;
			noun = ""; // Clears the variables
			verb = "";
		}
		//File input ends here.
		Player1.performAction(verb, noun);
		//At this point, noun and verb are how they should be, functions can use them.

	}
}