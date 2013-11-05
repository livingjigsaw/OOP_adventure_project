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

bool InventoryItem::use(List* roomInventory, string& target){
	InventoryItem* now = this;
	Item* match = roomInventory->findByCondition(now->name());
	if (match==NULL)
		return 0;
	else
		match->currentState(0); //changes environmental var state TO FALSE TO MAKE IT IGNORED, for the description loader
		target = match->name();
		match->changeEnv(roomInventory);
		return 1;
}

bool pieceItem::use(List* charInventory, string& target){
	pieceItem* now = this;
	Item* match = charInventory->findByName(now->target());
	if (match==NULL)
		return 0;
	else{
		match->currentState(1); //changes environmental var state TO FALSE TO MAKE IT IGNORED, for the description loader
		target = match->name();
		charInventory->removeNth(charInventory->find(now));
		return 1;
		}
}

bool StatusItem::use(List* roomInventory, string& target){ //assume the commad function determines if this is a status or not
	StatusItem* now = this;
	Item* match = roomInventory->findByCondition(now->name());
	if (match==NULL)
		return 0;
	else{
		match->currentState(1); //changes environmental var state TO FALSE TO MAKE IT IGNORED, for the description loader
		target = match->name();
		match->changeEnv(roomInventory);
		return 1;
		}
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