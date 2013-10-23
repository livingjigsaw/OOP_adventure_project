#include <iostream>
#include <sstream>
//#include "1.h"

using namespace std;

int main(){
	char check1;
	bool gameOver = false;
	cout << "Welcome to [WIP] Adventure! Do you need instructions? (Y/N)" << endl;
	cin >> check1;
	if (check1 == 'Y' || check1 == 'y')
	{
		cout << "You navigate this game purely through text instructions." << endl;
		cout << "When prompted, please insert what you wish your character to do using commands of not more than two words." << endl;
		cout << "If stuck, type 'Help' for some hints." << endl;
		cout << endl;
	}
	cout << "You wake up. You are on a stiff bed in a small, generic room with basic living necessities." << endl;
	cout << "The room seems old, partially ruined." << endl;
	cout << "There is one door, in an arbitrary direction that will be designated as north." << endl;
	cout << "There is a clock, a painting, a pocketknife, and a notebook in the room." << endl;
	while (!gameOver)
	{
		string row;
		string verb = "";
		string noun = "";
		getline (cin, row);
		stringstream ss (row);
		ss >> verb;
		ss >> noun;
		if (noun == "")
		{
			noun = verb;
			verb = "";
		}
		if (noun == "Quit")
			break;
		if (ss.rdbuf()->in_avail() != 0)
		{
			cout << "Please only enter up to 2 words only." << endl;
			noun = "";
			verb = "";
		}
	}
}