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
	InventoryItem Journal("JOURNAL", "A small notebook with writing in it. There are some references to cakes and lies.");
	InventoryItem PocketKnife("POCKETKNIFE", "A small, metal knife. Slightly rusted and not very sharp.");
	InventoryItem Clock("ALARMCLOCK", "Permanently stuck at 3:16.");
	InventoryItem Painting("PAINTING", "A picture of a bearded man whose eyes seems to follow you wherever you move in the room.");
	EnvironmentItem Hatch("HATCH", "orb");
	InventoryItem Flashlight("FLASHLIGHT", "Small, yet emits a powerful beam.");
	//Item Darkness("Darkness");
//	Item GeneratorSwitch("GeneratorSwitch");
//	Item OrbButton("OrbButton");
//	Item Orb("Orb");
    // first Room
	List firstRList;// First room's item list.
//		initialize(firstRList); //herpaderp the list has no constructor
	firstRList.append((Item*)&PocketKnife);
	firstRList.append((Item*)&Journal);
	firstRList.append((Item*)&Clock);
	firstRList.append((Item*)&Painting);
	string* firstRMC = new string [1]; // First room's move command.
	Room** firstRMD =new Room*[1]; firstRMD[0]=NULL; // First room's move destination. URGENT! THIS ONLY WORKS AFTER THE SECOND ROOM HAS BEEN CONSTRUCTED.
   string n="Firstroom";
    string SD="a small, generic room with basic living necessities. There is one door to the north.";
    string LD="There's a stiff bed in a small, generic room with basic living necessities. The room seems old, partially ruined. There is one door, in an arbitrary direction that will be designated as north.";
	Room FirstRoom(n, 3, &firstRList ,SD ,LD, firstRMC,firstRMD, 1); //Constructing the first room.

    
    
    //second Room
    List secondRList;// second room's item list.
    cout << "debug42\n"; //*********current final success**********
    //		initialize(firstRList); //herpaderp the list has no constructor
	secondRList.append((Item*)&Hatch);
	cout << "debug52\n";
	secondRList.append((Item*)&PocketKnife);
	cout << "debug62\n";
	secondRList.append((Item*)&Clock);
	cout << "debug72\n";
	secondRList.append((Item*)&Painting);
	cout << "debug82\n";
	string* secondRMC = new string [3]; // second room's move command.
	Room** secondRMD =new Room*[3]; secondRMD[0]=NULL; // second room's move
    string n2="Secondroom";
    string SD2="a large, open room that's somewhat bare. There is a glass room in the Center of this room, and a wooden door to the east, and a massive opening where the hatch once was. ";
    string LD2="Warning lights are flashing next to the massive opening, but no alarms are going off. the control room blinks many colors at off intervals";
	Room SecondRoom(n2, 3, &secondRList ,SD2,LD2, secondRMC,secondRMD, 3);
    //Constructing the second room.
    
    
    //third Room
    List thirdRList;// third room's item list.
    cout << "debug42\n"; //*********current final success**********
    //		initialize(firstRList); //herpaderp the list has no constructor
	thirdRList.append((Item*)&Hatch);
	cout << "debug52\n";
	thirdRList.append((Item*)&PocketKnife);
	cout << "debug62\n";
	thirdRList.append((Item*)&Clock);
	cout << "debug72\n";
	thirdRList.append((Item*)&Painting);
	cout << "debug82\n";
	string* thirdRMC = new string [1]; // second room's move command.
	Room** thirdRMD =new Room*[1]; thirdRMD[0]=NULL; // second room's move
    string n3="Thirdroom";
    string SD3="in the glass room, there is a large array of switches and controls, all out of power there is a flashlight there, as well as a first aid kit";
    string LD3=" no long longDescript";
	Room ThirdRoom(n3, 3, &thirdRList ,SD3,LD3, thirdRMC,thirdRMD, 1);
    //Constructing the third room.
    
    
    //Fourth Room
    List fourthRList;// third room's item list.
    cout << "debug42\n"; //*********current final success**********
    //		initialize(firstRList); //herpaderp the list has no constructor
	fourthRList.append((Item*)&Hatch);
	cout << "debug52\n";
	fourthRList.append((Item*)&PocketKnife);
	cout << "debug62\n";
	fourthRList.append((Item*)&Clock);
	cout << "debug72\n";
	fourthRList.append((Item*)&Painting);
	cout << "debug82\n";
	string* fourthRMC = new string [2]; // second room's move command.
	Room** fourthRMD =new Room*[2]; fourthRMD[0]=NULL; // second room's move
    string n4="Thirdroom";
    string SD4="through the wooden door, is a pitch black room.";
    string LD4=" There is a machine with the word generator on the wall behind it, as well as a switch in the on position, but it doesn't make connection(the pocketknife can be jammed there to establish connetion, but electrocutes the player if not in off position) so yes, someone can die in the demo TROLLOLOLZ ";
	Room FourthRoom(n4, 3, &fourthRList ,SD4,LD4, fourthRMC,fourthRMD, 2);
    //Constructing the Fourth room.
    
    cout<<firstRMD[0]<<endl;
    firstRMC[0]="NORTH";
    firstRMD[0]=&SecondRoom;
    cout<<firstRMD[0]<<endl;
    secondRMC[0]="SOUTH";
    secondRMD[0]=&FirstRoom;
    
    secondRMC[1]="INSIDE";
    secondRMD[1]=&ThirdRoom;
    thirdRMC[0]="OUTSIDE";
    thirdRMD[0]=&SecondRoom;
    
    secondRMC[2]="EAST";
    secondRMD[2]=&FourthRoom;
    
    fourthRMC[0]="WEST";
    fourthRMD[0]=&SecondRoom;

	
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
	cout << "You're in " << Player1.getDescription("", "") <<endl;

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
		cout << endl;
		if (noun == "")
		{
			//noun = verb;
			//verb = "";
		}
		if (verb == "QUIT")
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
		cout << endl;
	
	}
}