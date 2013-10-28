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
	InventoryItem Journal("JOURNAL", "A small notebook with writing in it. There are some references to cakes and lies.");
	cout << "debug2\n";
	InventoryItem PocketKnife("POCKETKNIFE", "A small knife. Slightly rusted but otherwise sharp.");
	InventoryItem Clock("ALARMCLOCK", "Permanently stuck at 3:16.");
	InventoryItem Painting("PAINTING", "A picture of a bearded man whose eyes seems to follow you wherever you move in the room.");
//	InventoryItem Hatch("Hatch");
	InventoryItem Flashlight("FLASHLIGHT", "Small, yet emits a powerful beam.");
	//Item Darkness("Darkness");
//	Item GeneratorSwitch("GeneratorSwitch");
//	Item OrbButton("OrbButton");
//	Item Orb("Orb");
		cout << "debug3\n";
    // first Room
	List firstRList;// First room's item list.
		cout << "debug4\n"; //*********current final success**********
//		initialize(firstRList); //herpaderp the list has no constructor
	firstRList.append((Item*)&PocketKnife);
	cout << "debug5\n";
	firstRList.append((Item*)&Journal);
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
    
    
    
    //second Room
    List secondRList;// second room's item list.
    cout << "debug42\n"; //*********current final success**********
    //		initialize(firstRList); //herpaderp the list has no constructor
	secondRList.append((Item*)&Journal);
	cout << "debug52\n";
	secondRList.append((Item*)&PocketKnife);
	cout << "debug62\n";
	secondRList.append((Item*)&Clock);
	cout << "debug72\n";
	secondRList.append((Item*)&Painting);
	cout << "debug82\n";
	string* secondRMC = new string [1]; // second room's move command.
	Room** secondRMD =new Room*[1]; secondRMD[0]=NULL; // second room's move
    string n2="Secondroom";
    string SD2="A large, mess room with basic living necessities. There is one door to the south.";
    string LD2="You walk into a large, mess room with basic living necessities. The room seems new, empty. There is one door, in an arbitrary direction that will be designated as south.";
	Room SecondRoom(n2, 3, &secondRList ,SD2,LD2, secondRMC,secondRMD, 1);
    //Constructing the first room.
    
    cout<<firstRMD[0]<<endl;
    firstRMC[0]="NORTH";
    firstRMD[0]=&SecondRoom;
    cout<<firstRMD[0]<<endl;
    secondRMC[0]="SOUTH";
    secondRMD[0]=&FirstRoom;
	
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