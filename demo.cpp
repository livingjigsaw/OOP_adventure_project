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
	EnvironmentItem Hatch("HATCH", "POCKETKNIFE", "MOVE", "WEST");
	

    List secondRList;// second room's item list.
    //cout << "debug42\n"; //*********current final success**********
    //		initialize(firstRList); //herpaderp the list has no constructor
	secondRList.append((Item*)&Hatch);

	string* secondRMC = new string [3]; // second room's move command.
	Room** secondRMD =new Room*[3]; secondRMD[0]=NULL; // second room's move
    string n2="Secondroom";
    string SD2="a large, open room that's somewhat bare. There is a glass room in the Center of this room, and a wooden door to the east, and a massive opening where the hatch once was.";
    string LD2="Warning lights are flashing next to the massive opening, but no alarms are going off. the control room blinks many colors at off interval";
	Room SecondRoom(n2, 3, &secondRList ,SD2,LD2, secondRMC,secondRMD, 3);
    //Constructing the second room.
    
    
    //third Room
	InventoryItem Flashlight("FLASHLIGHT", "Small, yet emits a powerful beam.");
    List thirdRList;// third room's item list.
	thirdRList.append((Item*)&Flashlight);

	string* thirdRMC = new string [1]; // second room's move command.
	Room** thirdRMD =new Room*[1]; thirdRMD[0]=NULL; // second room's move
    string n3="Thirdroom";
    string SD3="the glass room, where there is a large array of switches and controls, all out of power.";
    string LD3=" This seems to be a control room of some sort";
	Room ThirdRoom(n3, 3, &thirdRList ,SD3,LD3, thirdRMC,thirdRMD, 1);
    //Constructing the third room.
    
    
    //Fourth Room
    List fourthRList;// Fourth room's item list.

	string* fourthRMC = new string [2]; // second room's move command.
	Room** fourthRMD =new Room*[2]; fourthRMD[0]=NULL; // second room's move
    string n4="Fourthroom";
    string SD4="through the wooden door, is a pitch black room.";
    string LD4=" There is a machine with the word generator on the wall behind it, as well as a switch in the on position, but it doesn't make connection(the pocketknife can be jammed there to establish connetion, but electrocutes the player if not in off position) so yes, someone can die in the demo TROLLOLOLZ ";
	Room FourthRoom(n4, 3, &fourthRList ,SD4,LD4, fourthRMC,fourthRMD, 2);
    //Constructing the Fourth room.
    
    
    //Fifth Room
    List fifthRList;// Fifth room's item list.
	fifthRList.append((Item*)&Hatch);

	string* fifthRMC = new string [1]; // second room's move command.
	Room** fifthRMD =new Room*[1]; fifthRMD[0]=NULL; // second room's move
    string n5="Fifthroom";
    string SD5="You stand in a bare abandoned laboratory, still clutching the orb. The smell of electricity is in the air as you step down from a raised platform in the middle of the room.";
    string LD5=" You see a single door to the west (ROOM 6) but realize it is locked electronically, requiring a palm scan to unlock it. (If player pressed button) - You see an open compartment with what looks like a dart gun (DARTGUN) in it. (Not required to finish game).";
	Room FifthRoom(n5, 3, &fifthRList ,SD5,LD5, fifthRMC,fifthRMD, 1);
    //Constructing the Fifth room.
    
    
    //Sixth Room
    List sixthRList;// Fifth room's item list.
  
	sixthRList.append((Item*)&Hatch);

	string* sixthRMC = new string [2]; // second room's move command.
	Room** sixthRMD =new Room*[2]; sixthRMD[0]=NULL; // second room's move
    string n6="Sixthroom";
    string SD6="You are in a hallway. There are doors to the east (ROOM 5), north (ROOM 7) and south (Can't enter, door is barricaded). There are signs above each of the doors but two of them are so rusted you can't make out a word.The sign over the south door shows 'STAIRWELL'. ";
    string LD6=" In what you hope is red paint, you see the words 'GET DOWNSTAIRS IF YOU STILL CAN.' scrawled in large letters across a wall. You hear dripping in the distance.";
	Room SixthRoom(n6, 3, &sixthRList ,SD6,LD6, sixthRMC,sixthRMD, 2);
    //Constructing the Sixth room.
    
    //Seventh Room
    List seventhRList;// Seventh room's item list.
    //cout << "debug42\n"; //*********current final success**********
    //		initialize(firstRList); //herpaderp the list has no constructor
	seventhRList.append((Item*)&Hatch);
	string* seventhRMC = new string [3]; // second room's move command.
	Room** seventhRMD =new Room*[3]; seventhRMD[0]=NULL; // second room's move
    string n7="Seventhroom";
    string SD7="You are in a hallway. There are doors to the east (ROOM 5), north (ROOM 7) and south (Can't enter, door is barricaded). There are signs above each of the doors but two of them are so rusted you can't make out a word.The sign over the south door shows 'STAIRWELL'. ";
    string LD7=" In what you hope is red paint, you see the words 'GET DOWNSTAIRS IF YOU STILL CAN.' scrawled in large letters across a wall. You hear dripping in the distance.";
	Room SeventhRoom(n7, 3, &seventhRList ,SD7,LD7, seventhRMC,seventhRMD, 2);
    //Constructing the Seventh room.
    
    //Eighth Room
    List eighthRList;// Eighth room's item list.
	eighthRList.append((Item*)&Hatch);
	
	string* eighthRMC = new string [2]; // second room's move command.
	Room** eighthRMD =new Room*[2]; eighthRMD[0]=NULL; // second room's move
    string n8="EighthRoom";
    string SD8="A door to the west leads back to the cafeteria (ROOM 7) You have found the source of the smell. In the restroom, two unidentifiable dead bodies slump against a wall.";
    string LD8=" Their bodies are covered with bite marks, and their limbs look as if they were torn off. One of the bodies wears a lab coat, in his hands he cradles a device (DEVICE), his last act seemed to be protecting the device. The other body is even more mangled, but you conclude that he was a janitor based on the ring of keys(JANITORKEYS) he has looped on around his belt.";
	Room EighthRoom(n8, 3, &eighthRList ,SD8,LD8, eighthRMC,eighthRMD, 1);
    //Constructing the Eighth room.
    
    
    //Ninth Room
    List ninthRList;// Ninth room's item list.
	ninthRList.append((Item*)&Hatch);

	string* ninthRMC = new string [2]; // second room's move command.
	Room** ninthRMD =new Room*[2]; ninthRMD[0]=NULL; // second room's move
    string n9="NinthRoom";
    string SD9="You walk into the room and right on to the edge of a gaping hole. You have found the source of the dripping sounds: A giant vat of what is presumably strong acid lies partially smashed on one end of the room. After an indeterminable time, the acid has corroded into the ground. Acid continues to drip on to the floor below, sizzling as it comes into contact with the tiled floor.";
    string LD9=" Once your eyes adjusted to the low light, you see a blue glint on the other side of the room; it seems the acid had also destroyed part of a safe. However, you can't reach the safe because of the huge hole in the middle of the room. A door to the south leads back to the cafeteria (ROOM 7). You can climb down the hole to the floor below, but you won't be able to return. (ROOM 10) If the player chooses to USE metallic orb, the blue gem (sapphire) would be attracted to the orb. ";
	Room NinthRoom(n9, 3, &ninthRList ,SD9,LD9, ninthRMC,ninthRMD, 2);
    //Constructing the Ninth room.
    
    //Tenth Room
    List tenthRList;// Tenth room's item list.
	tenthRList.append((Item*)&Hatch);
    
	string* tenthRMC = new string [3]; // second room's move command.
	Room** tenthRMD =new Room*[3]; tenthRMD[0]=NULL; // second room's move
    string n10="TenthRoom";
    string SD10="You're in another hallway. The walls are covered with peeling wallpaper, with brown, foul smelling stains splattered on them.";
    string LD10=" There is a door to the north (ROOM 11) and another to the south (ROOM 12). The only light in the hallway comes from the hole in the ceiling and the sound of acid dripping and sizzling fills the hallway. You hear a scraping noise in the distance. ";
	Room TenthRoom(n10, 3, &tenthRList ,SD10,LD10,tenthRMC,tenthRMD, 3);
    //Constructing the Tenth room.
    
    //Eleventh Room
    List eleventhRList;// Eleventh room's item list.
	eleventhRList.append((Item*)&Hatch);
    
	string* eleventhRMC = new string [2]; // second room's move command.
	Room** eleventhRMD =new Room*[2]; eleventhRMD[0]=NULL; // second room's move
    string n11="EleventhRoom";
    string SD11="You're in another hallway. The walls are covered with peeling wallpaper, with brown, foul smelling stains splattered on them.";
    string LD11=" There is a door to the north (ROOM 11) and another to the south (ROOM 12). The only light in the hallway comes from the hole in the ceiling and the sound of acid dripping and sizzling fills the hallway. You hear a scraping noise in the distance. ";
	Room EleventhRoom(n11, 3, &eleventhRList ,SD11,LD11,eleventhRMC,eleventhRMD, 1);
    //Constructing the Eleventh room.
    
    //Twelfth Room
    List twelfthRList;// Twelfth room's item list.
	twelfthRList.append((Item*)&Hatch);
    
	string* twelfthRMC = new string [2]; // second room's move command.
	Room** twelfthRMD =new Room*[2]; twelfthRMD[0]=NULL; // second room's move
    string n12="TwelfthRoom";
    string SD12="You enter the room and immediately see a door east(leading to ROOM 13) blocked(LOCKEDDOOR) by two... legless beings (ZOMBIES). You are surprised to see that these are still alive, but enable to move foward. The scraping noise is caused by their clawing of the floor, and upon noticing you they look up.";
    string LD12=" You are startled to see that they both have the exact same face. Your face. In fact, they look exactly like you, except for the minor detail of not having legs. A door to the north leads back to the hallway. (ROOM 10)(TWO THINGS BLOCK THE WAY FORWARD: THE ZOMBIES AND THE LOCKED DOOR. THE PLAYER WOULD FIRST HAVE TO SHOOT THE ZOMBIES WITH THE DART GUN AND THEN OPEN THE DOOR USING THE JANITOR KEYS)" ;
	Room TwelfthRoom(n12, 3, &eleventhRList ,SD12,LD12,twelfthRMC,twelfthRMD, 2);
    //Constructing the Twelfth room.
    
    //Thirteenth Room
    List thirteenthRList;// Thirteenth room's item list.
	thirteenthRList.append((Item*)&Hatch);
    
	string* thirteenthRMC = new string [2]; // second room's move command.
	Room** thirteenthRMD =new Room*[2]; twelfthRMD[0]=NULL; // second room's move
    string n13="ThirteenthRoom";
    string SD13="You walk in and immediately get hit by a foul stench. There are dead bodies everywhere. Most have decomposed to the bone, but you make out some details: The bodies wearing lab coats are missing limbs while the others looks exactly alike. Like you.";
    string LD13=" One of the bodies wearing a lab coat clutches a a few pieces of paper. (NOTES) There is a door to the weat (BACK TO ROOM 12) and another to the east. (ROOM 14), but it is blocked by a hatch that looks like it can receive a spherical object. You feel sick and want to get out of the room as soon as possible.";
	Room ThirteenthRoom(n13, 3, &thirteenthRList ,SD13,LD13,thirteenthRMC,thirteenthRMD, 2);
    //Constructing the Thirteenth room.
    
    
    //Fourteenth Room
    List fourteenthRList;// Fourteenth room's item list.
	fourteenthRList.append((Item*)&Hatch);
    
	string* fourteenthRMC = new string [2]; // second room's move command.
	Room** fourteenthRMD =new Room*[2]; twelfthRMD[0]=NULL; // second room's move
    string n14="FourteenthRoom";
    string SD14="You walk into a futuristic room with sleek metal walls on all sides. A single large screen dominates the far end, opposite the door.";
    string LD14=" Big bold letters spell out 'CONTINUE?' on the screen. Right below the screen is a big red button. There is a door to the west (ROOM 13). Type 'Continue' to press the BIG RED BUTTON!";
	Room FourteenthRoom(n14, 3, &fourteenthRList ,SD14,LD14,fourteenthRMC,fourteenthRMD, 1);
    //Constructing the Thirteenth room.

    //room connection
    //cout<<firstRMD[0]<<"debug1" <<endl;
    firstRMC[0]="NORTH";
    firstRMD[0]=&SecondRoom;
    //cout<<firstRMD[0]<<endl;
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
    
    fourthRMC[1]="TELEPORTATION";
    fourthRMD[1]=&FifthRoom;
    
    fifthRMC[0]="WEST";
    fifthRMD[0]=&SixthRoom;
    //    cout<<"\n debug A\n";
    sixthRMC[0]="EAST";
    sixthRMD[0]=&FifthRoom;
    sixthRMC[0]="NORTH";
    sixthRMD[0]=&SeventhRoom;
    //        cout<<"\n debug B\n"; // we get here
    seventhRMC[0]="SOUTH";
    seventhRMD[0]=&SixthRoom;
	//cout<<"\n debug B1\n"; // we get here
    seventhRMC[1]="EAST";
    seventhRMD[1]=&EighthRoom;
	//cout<<"\n debug B2\n"; // we get here
    seventhRMC[2]="NORTH";
	//cout<<"\n debug B3\n"; // we get here
    seventhRMD[2]=&NinthRoom;
    //        cout<<"\n debug C\n"; // but not here
    eighthRMC[0]="WEST";
    eighthRMD[0]=&SeventhRoom;
//not getting here
    ninthRMC[0]="SOUTH";
    ninthRMD[0]=&SeventhRoom;
    ninthRMC[1]="BELOW";
    ninthRMD[1]=&TenthRoom;
    
    tenthRMC[0]="UP";
    tenthRMD[0]=&NinthRoom;
    tenthRMC[1]="NORTH";
    tenthRMD[1]=&EleventhRoom;
    tenthRMC[2]="SOUTH";
    tenthRMD[2]=&TwelfthRoom;
    
    eleventhRMC[0]="SOUTH";
    eleventhRMD[0]=&TenthRoom;
    
    twelfthRMC[0]="NORTH";
    twelfthRMD[0]=&TenthRoom;
    twelfthRMC[1]="EAST";
    twelfthRMD[1]=&ThirteenthRoom;
    
    thirteenthRMC[0]="WEST";
    thirteenthRMD[0]=&TwelfthRoom;
    thirteenthRMC[1]="EAST";
    thirteenthRMD[1]=&FourteenthRoom;
    
    fourteenthRMC[0]="WEST";
    fourteenthRMD[0]=&ThirteenthRoom;

	//done with room connection
	Player Player1(&FirstRoom);
	//cout<<"debug11\n";
	char check1;
	bool gameOver = false;
	cout << "Welcome to [WIP] Adventure! Do you need instructions? (Y/N)" << endl;
	cin >> check1;
	if (check1 == 'Y' || check1 == 'y')
	{
		cout << "You navigate this game purely through text instructions." << endl;
		cout << "When prompted, please insert what you wish your character to do using commands of not more than two words (And of the form 'verb + noun')." << endl;
		cout << "Moving is done by typing 'Go' followed by a cardinal direction. (i.e: North, South, East and West)" << endl;
		cout << "If stuck, type 'Help' for some hints." << endl;
		cout << endl;
	}
	cout << "You're in " << Player1.getDescription("", "") <<endl;
	string junk;
	getline (cin, junk);
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