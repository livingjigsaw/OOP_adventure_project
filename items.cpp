#include "room.h"

// items implmentation
using namespace std;

bool InventoryItem::take(List* roomInventory, List* charInventory){
	InventoryItem* now = this;
	charInventory -> append((Item*)now);
	int location = roomInventory -> find((Item*)now);
	roomInventory -> removeNth(location);
	return 1;
}
	
bool InventoryItem::drop(List* roomInventory, List* charInventory){
	InventoryItem* now = this;
	roomInventory -> append((Item*)now);
	int location = charInventory -> find((Item*)now);
	charInventory -> removeNth(location);
	return 1;
}

bool InventoryItem::observe(){
	cout << this->description() << endl;
	return 1;
}

/*bool EdibleItem::eat(List<Item*>* charInventory){
	EdibleItem* now = this;
	int location = find(*charInventory,(Item*)now);
	removeNth(*charInventory, location);
	return 1;
}*/

bool EnvironmentItem::changeEnv(List* roomInventory){	//searching should be done by handling function;
	EnvironmentItem* now=this;
	int location = roomInventory -> find((Item*)now);
	roomInventory -> removeNth(location);
	return 1;
}