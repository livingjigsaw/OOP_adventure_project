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
	//InventoryItem Painting("PAINTING", "A picture of a bearded man whose eyes seems to follow you wherever you move in the room.");
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
	//firstRList.append((Item*)&Painting);
	string* firstRMC = new string [1]; // First room's move command.
	Room** firstRMD =new Room*[1]; firstRMD[0]=NULL; // First room's move destination. URGENT! THIS ONLY WORKS AFTER THE SECOND ROOM HAS BEEN CONSTRUCTED.
   string n="Firstroom";
    string SD="a small, generic room with basic living necessities. You shake off a minor headache, and can't help but feel that you've been here before. There is one door to the north. (Note: Type 'Look' to investigate your surroundings further.";
    string LD="There's a stiff bed in a small, generic room with basic living necessities. The room seems old, partially ruined. There is one door, in an arbitrary direction that will be designated as north.";
	Room FirstRoom(n, 3, &firstRList ,SD ,LD, firstRMC,firstRMD, 1); //Constructing the first room.

    
    
    //second Room
	//EnvironmentItem Hatch("HATCH", "POCKETKNIFE", "MOVE", "WEST"); //Removed this for final game.
	

    List secondRList;// second room's item list.
    //cout << "debug42\n"; //*********current final success**********
    //		initialize(firstRList); //herpaderp the list has no constructor
	//secondRList.append((Item*)&Hatch);

	string* secondRMC = new string [3]; // second room's move command.
	Room** secondRMD =new Room*[3]; secondRMD[0]=NULL; // second room's move
    string n2="Secondroom";
    string SD2="a large, open room that's somewhat bare. There is a glass room in the center of this room (type 'Move inside' to enter the room), and a wooden door to the east.";
    string LD2="Warning lights are flashing next to the massive opening, but no alarms are going off.";
	Room SecondRoom(n2, 1, &secondRList ,SD2,LD2, secondRMC,secondRMD, 3);
    //Constructing the second room.
    
    
    //third Room
	InventoryItem Flashlight("FLASHLIGHT", "Small, yet emits a powerful beam.");
    InventoryItem Button("BUTTON", "The button says 'receive signal'.");
    List thirdRList;// third room's item list.
	thirdRList.append((Item*)&Flashlight);
    thirdRList.append((Item*)&Button);

	string* thirdRMC = new string [1]; // second room's move command.
	Room** thirdRMD =new Room*[1]; thirdRMD[0]=NULL; // second room's move
    string n3="Thirdroom";
    string SD3="the glass room, where there is a large array of switches and controls, all out of power.";
    string LD3=" This seems to be a control room of some sort";
	Room ThirdRoom(n3, 2, &thirdRList ,SD3,LD3, thirdRMC,thirdRMD, 1);
    //Constructing the third room.
    
    
    //Fourth Room
    EnvironmentItem Generator("GENERATOR", "POCKETKNIFE", "MOVE", "EAST");
    InventoryItem Orb("ORB", "A metallic orb, very metllic and shiny, perfectly smooth except for an indentation.");
    List fourthRList;// Fourth room's item list.
    fourthRList.append((Item*)&Orb);
    fourthRList.append(&Generator);

	string* fourthRMC = new string [2]; // second room's move command.
	Room** fourthRMD =new Room*[2]; fourthRMD[0]=NULL; // second room's move
    string n4="Fourthroom";
    string SD4="a pitch black room. A door lies to the west, where you came from.";
    string LD4="There is a machine with the word generator on the wall behind it, as well as a switch in the on position, but it doesn't make a connection. There is a mysterious smooth sphere in the middle of the room, as well as a locked door to the south that seems to be connected to the generator.";
	Room FourthRoom(n4, 1, &fourthRList ,SD4,LD4, fourthRMC,fourthRMD, 2);
    //Constructing the Fourth room.
    
    
    //Fifth Room
    InventoryItem Dartgun("DARTGUN", "A dart gun loaded with some sort of tranquilizer dart.");
    List fifthRList;// Fifth room's item list.
	fifthRList.append((Item*)&Dartgun);

	string* fifthRMC = new string [2]; // second room's move command.
	Room** fifthRMD =new Room*[2]; fifthRMD[0]=NULL; // second room's move
    string n5="Fifthroom";
    string SD5="a bare abandoned laboratory. The smell of electricity is in the air as you walk in from the north. ";
    string LD5=" You see a single door to the west but realize it is locked electronically, requiring a palm scan to unlock it. You see an open compartment that holds a dartgun. Tentatively you place your hand on the scanner and to your surprise the door slides open.";
	Room FifthRoom(n5, 1, &fifthRList ,SD5,LD5, fifthRMC,fifthRMD, 2);
    //Constructing the Fifth room.
    
    
    //Sixth Room
    List sixthRList;// Fifth room's item list.
  
	//sixthRList.append((Item*)&Clock);

	string* sixthRMC = new string [2]; // second room's move command.
	Room** sixthRMD =new Room*[2]; sixthRMD[0]=NULL; // second room's move
    string n6="Sixthroom";
    string SD6="in a hallway. There are doors to the east, north and south. There are signs above each of the doors but two of them are so rusted you can't make out a word. The sign over the south door shows 'STAIRWELL'. ";
    string LD6=" In what you hope is red paint, you see the words 'GET DOWNSTAIRS IF YOU STILL CAN' scrawled in large letters across a wall. Upon inspection, the south door seems to be barricaded. You hear dripping in the distance.";
	Room SixthRoom(n6, 0, &sixthRList ,SD6,LD6, sixthRMC,sixthRMD, 2);
    //Constructing the Sixth room.
    
    //Seventh Room
    InventoryItem Chocolate("CHOCOLATE", "A chocolate bar that seems slightly mouldy.");
    InventoryItem ZipFizz("ZIPFIZZ", "A small bottle of what seems to be a brain-enhancing stimulant.");
    List seventhRList;// Seventh room's item list.
    //cout << "debug42\n"; //*********current final success**********
    //		initialize(firstRList); //herpaderp the list has no constructor
	seventhRList.append((Item*)&Chocolate);
    seventhRList.append((Item*)&ZipFizz);
	string* seventhRMC = new string [3]; // second room's move command.
	Room** seventhRMD =new Room*[3]; seventhRMD[0]=NULL; // second room's move
    string n7="Seventhroom";
    string SD7="a spacious hall. There are long tables with benches on either side on them along the sides of the room. Judging by the layout of the room, you conclude that it used to be a cafeteria of some sort. A smell of decay fills your nose and make you feel slightly nauseous.";
    string LD7="There is a counter near the back of the room with boxes of food. Most are empty, but you see some supplies. To the south is a door leading back to the hallway. To the east is a small door leading to what is presumably a restroom. To the north is another door with a palm scanner again, which slides open when you scan your palm. The sound of dripping is louder here, with a slight sizzle after each drip.";
	Room SeventhRoom(n7, 2, &seventhRList ,SD7,LD7, seventhRMC,seventhRMD, 3);
    //Constructing the Seventh room.
    
    //Eighth Room
    InventoryItem Device("DEVICE", "A bundle of wires and circuit boards, there is no way to tell the function of this contraption.");
    InventoryItem Janitorkeys("JANITORKEYS", "A loop of keys.");
    List eighthRList;// Eighth room's item list.
	eighthRList.append((Item*)&Device);
    eighthRList.append((Item*)&Janitorkeys);
	
	string* eighthRMC = new string [2]; // second room's move command.
	Room** eighthRMD =new Room*[2]; eighthRMD[0]=NULL; // second room's move
    string n8="EighthRoom";
    string SD8= "the restroom. You have found the source of the smell. Two unidentifiable dead bodies slump against a wall.";
    string LD8= " Their bodies are covered with bite marks, and their limbs look as if they were torn off. One of the bodies wears a lab coat, in his hands he cradles a device, his last act seemed to be protecting the device. The other body is even more mangled, but you conclude that he was a janitor based on the ring of keys he has looped on around his belt.  A door to the west leads back to the cafeteria. ";
	Room EighthRoom(n8, 2, &eighthRList ,SD8,LD8, eighthRMC,eighthRMD, 1);
    //Constructing the Eighth room.
    
    
    //Ninth Room
    InventoryItem Sapphire("SAPPHIRE", "A shiny blue gem, precisely carved into a round shape, as if it was meant to be embedded in some larger object.");
    List ninthRList;// Ninth room's item list.
	ninthRList.append((Item*)&Sapphire);

	string* ninthRMC = new string [2]; // second room's move command.
	Room** ninthRMD =new Room*[2]; ninthRMD[0]=NULL; // second room's move
    string n9="NinthRoom";
    string SD9="the room and right on to the edge of a gaping hole. You have found the source of the dripping sounds: A giant vat of what is presumably strong acid lies partially smashed on one end of the room. After an indeterminable time, the acid has corroded into the ground. Acid continues to drip on to the floor below, sizzling as it comes into contact with the tiled floor.";
    string LD9=" Once your eyes adjusted to the low light, you see a blue glint on the other side of the room; it seems the acid had also destroyed part of a safe, and its contents are obtainable. A door to the south leads back to the cafeteria. You can climb down the hole to the floor below ('Move Down'), but you won't be able to return. ";
	Room NinthRoom(n9, 1, &ninthRList ,SD9,LD9, ninthRMC,ninthRMD, 2);
    //Constructing the Ninth room.
    
    //Tenth Room
    List tenthRList;// Tenth room's item list.
    
	string* tenthRMC = new string [2]; // second room's move command.
	Room** tenthRMD =new Room*[2]; tenthRMD[0]=NULL; // second room's move
    string n10="TenthRoom";
    string SD10="another hallway. The walls are covered with peeling wallpaper, with brown, foul smelling stains splattered on them.";
    string LD10=" There is a door to the north and another to the south. The only light in the hallway comes from the hole in the ceiling and the sound of acid dripping and sizzling fills the hallway. You hear a scraping noise in the distance. ";
	Room TenthRoom(n10, 0, &tenthRList ,SD10,LD10,tenthRMC,tenthRMD, 2);
    //Constructing the Tenth room.
    
    //Eleventh Room
    InventoryItem  Notebook("NOTEBOOK", "A journal belonging to one of the head scientists. It seemed that the scientists were attempting to create a clone of an influencial politican but failed repeatedly. The failed experiments grew feral and violent and were kept under lock. The journal ends by stating that the scientists had isolated the problematic gene and are working on a serum to cure it.");
    List eleventhRList;// Eleventh room's item list.
	eleventhRList.append((Item*)&Notebook);
    
	string* eleventhRMC = new string [2]; // second room's move command.
	Room** eleventhRMD =new Room*[2]; eleventhRMD[0]=NULL; // second room's move
    string n11="EleventhRoom";
    string SD11="what seems to be yet another laboratory. You are startled to see posters with your face on them plastered all over the room. A whiteboard hangs on a wall. On it are descriptions of DNA sequences and what looks suspiciously like a picture of your forearm.";
    string LD11="A scientific journal lies on a desk. A door to the south leads back to the hallway.";
	Room EleventhRoom(n11, 1, &eleventhRList ,SD11,LD11,eleventhRMC,eleventhRMD, 1);
    //Constructing the Eleventh room.
    
    //Twelfth Room
    EnvironmentItem Lockeddoor("LOCKEDDOOR", "JANITORKEYS", "MOVE", "EAST");
    EnvironmentItem Zombie("ZOMBIES","DARTGUN","MOVE", "EAST");
    List twelfthRList;// Twelfth room's item list.
	twelfthRList.append(&Lockeddoor);
    twelfthRList.append(&Zombie);
    
	string* twelfthRMC = new string [2]; // second room's move command.
	Room** twelfthRMD =new Room*[2]; twelfthRMD[0]=NULL; // second room's move
    string n12="TwelfthRoom";
    string SD12="the room and immediately see a door east blocked by two... legless beings. You are surprised to see that the creatures are still alive, but enable to move foward. The scraping noise is caused by their clawing of the floor, and upon noticing you they look up.";
    string LD12=" You are startled to see that they both have the exact same face. Your face. In fact, they look exactly like you, except for the minor detail of not having legs. A door to the north leads back to the hallway." ;
	Room TwelfthRoom(n12, 2, &twelfthRList ,SD12,LD12,twelfthRMC,twelfthRMD, 2);
    //Constructing the Twelfth room.
    
    //Thirteenth Room
    EnvironmentItem Lockedmagicdoor("SEALEDDOOR", "ORB", "MOVE", "EAST");
    InventoryItem Notes("NOTES", "Notes scribbed desperately by a trapped scientist. According to the notes, the serum created by the scientists to suppress the feral genes was tested on a clone but it only enhanced its strength. It murdered the scientists in the lab, and freed the rest of the clones. The clones started to hunt the scientists and attacking them. The remaining survivors barricaded themselves in this room for a week, but the clones were relentless. The scientists knew that they would die of starvation if they didn't try to escape, and seeing as the mysterious door to the east would not budge, their only option was to fight their way out. It ends with 'I'm sorry, may God help us all.'");
    List thirteenthRList;// Thirteenth room's item list.
	thirteenthRList.append((Item*)&Notes);
    thirteenthRList.append(&Lockedmagicdoor);
    
	string* thirteenthRMC = new string [2]; // second room's move command.
	Room** thirteenthRMD =new Room*[2]; twelfthRMD[0]=NULL; // second room's move
    string n13="ThirteenthRoom";
    string SD13="the room and immediately get hit by a foul stench. There are dead bodies everywhere. Most have decomposed to the bone, but you make out some details: The bodies wearing lab coats are missing limbs while the others looks exactly alike. Like you.";
    string LD13=" One of the bodies wearing a lab coat clutches a a few pieces of paper. There is a door to the west and another to the east, but it is blocked by a hatch that looks like it can receive a spherical object. You feel sick and want to get out of the room as soon as possible.";
	Room ThirteenthRoom(n13, 1, &thirteenthRList ,SD13,LD13,thirteenthRMC,thirteenthRMD, 2);
    //Constructing the Thirteenth room.
    
    
    //Fourteenth Room

    List fourteenthRList;// Fourteenth room's item list.
    
	string* fourteenthRMC = new string [1]; // second room's move command.
	Room** fourteenthRMD =new Room*[1]; twelfthRMD[0]=NULL; // second room's move
    string n14="FourteenthRoom";
    string SD14="a futuristic room with sleek metal walls on all sides. A single large screen dominates the far end, opposite the door.";
    string LD14=" Big bold letters spell out 'CONTINUE?' on the screen. Right below the screen is a big red button. There is a door to the west. Type 'PRESS REDBUTTON' to press the BIG RED BUTTON!";
	Room FourteenthRoom(n14, 1, &fourteenthRList ,SD14,LD14,fourteenthRMC,fourteenthRMD, 1);
    //Constructing the Thirteenth room.

    //room connections
    firstRMC[0]="NORTH";
    firstRMD[0]=&SecondRoom;

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
    
    fourthRMC[1]="SOUTH";
    fourthRMD[1]=&FifthRoom;
    
    fifthRMC[0]="WEST";
    fifthRMD[0]=&SixthRoom;
    fifthRMC[1]="NORTH";
    fifthRMD[1]=&FourthRoom;

    sixthRMC[0]="EAST";
    sixthRMD[0]=&FifthRoom;
    sixthRMC[1]="NORTH";
    sixthRMD[1]=&SeventhRoom;

    seventhRMC[0]="SOUTH";
    seventhRMD[0]=&SixthRoom;

    seventhRMC[1]="EAST";
    seventhRMD[1]=&EighthRoom;

    seventhRMC[2]="NORTH";

    seventhRMD[2]=&NinthRoom;

    eighthRMC[0]="WEST";
    eighthRMD[0]=&SeventhRoom;

    ninthRMC[0]="SOUTH";
    ninthRMD[0]=&SeventhRoom;
    ninthRMC[1]="DOWN";
    ninthRMD[1]=&TenthRoom;
    
    tenthRMC[0]="NORTH";
    tenthRMD[0]=&EleventhRoom;
    tenthRMC[1]="SOUTH";
    tenthRMD[1]=&TwelfthRoom;
    
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
	cout << "You wake up in " << Player1.getDescription("", "") <<endl;
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
		if (verb == "QUIT")
			break;
		if (ss.rdbuf()->in_avail() != 0) // Check if there're any words left in buffer, if there are, then user input was more than 2 words.
		{
			cout << "Please only enter up to 2 words only." << endl;
			noun = ""; // Clears the variables
			verb = "";
		}
        if (Player1.currentLocation() == &FourteenthRoom && verb == "PRESS" && noun == "REDBUTTON")
        {
            cout << "Your right hand balls into a fist, ready to satisfy your urge of slamming the seductively-huge red button. " << endl;
            cout << "As you bring your fist down, memories come flooding back. You're struck with a massive sense of deja vu as you realize that you've done this a million times before. " << endl;
            cout << "Mortified, you try your hardest to retract your fist, but it is too late - inertia has taken over at this point, and you can only watch in despair as your fist slam on to the button." << endl;
            cout << "A bright flash blinds you and you realize that you are on the ground." << endl;
            cout << "You wake up in a small generic room, with basic living necessities. You shake off a minor headache, and can't help but feel that you've been here before. There is a door to the north." << endl;
            cout << endl;
            gameOver = true;
            break;
        }
		//File input ends here.
		Player1.performAction(verb, noun);
		//At this point, noun and verb are how they should be, functions can use them.
		cout << endl;
	
	}
    cout << "THANKS FOR PLAYING [WIP] ADVENTURE!" << endl;

    //Deleting dynamic arrays.
    delete firstRMC;
    delete [] firstRMD;
    delete secondRMC;
    delete [] secondRMD;
    delete thirdRMC;
    delete [] thirdRMD;
    delete fourthRMC;
    delete [] fourthRMD;
    delete fifthRMC;
    delete [] fifthRMD;
    delete sixthRMC;
    delete [] sixthRMD;
    delete seventhRMC;
    delete [] seventhRMD;
    delete eighthRMC;
    delete [] eighthRMD;
    delete ninthRMC;
    delete [] ninthRMD;
    delete tenthRMC;
    delete [] tenthRMD;
    delete eleventhRMC;
    delete [] eleventhRMD;
    delete twelfthRMC;
    delete [] twelfthRMD;
    delete thirteenthRMC;
    delete [] thirteenthRMD;
    delete fourteenthRMC;
    delete [] fourteenthRMD;
}
