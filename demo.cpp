#include <iostream>
//#include "1.h"

using namespace std;

int main(){
	char check1;
	cout << "Welcome to [WIP] Adventure! Do you need instructions? (Y/N)" << endl;
	cin >> check1;
	if (check1 == 'Y' || check1 == 'y')
	{
		cout << "You navigate this game purely through text instructions." << endl;
		cout << "When prompted, please insert what you wish your character to do using commands of not more than two words." << endl;
		cout << "If stuck, type 'Help' for some hints." << endl;
	}
}