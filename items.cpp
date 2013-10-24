#include"1.h"

// items implmentation
using namespace std;

Item::Item(string n){
	name(n);
}

bool InventoryItem::take(List* roomInventory, List* charInventory){
	append(*charInventory, &this);
	int location = find(*roomInventory, &this);
	removeNth(*roomInventory, location);
	return 1;
}
	
bool InventoryItem::drop(List* roomInventory, List* charInventory){
	append(*roomInventory, &this);
	int location = find(*charInventory, &this);
	removeNth(*charInventory, location);
	return 1;
}

bool InventoryItem::observe(ostream lhs){
	lhs << this.description() << endl;
	return 1;
}

bool EdibleItem::eat(List* charInventory){
	int location = find(*charInventory, &this);
	removeNth(*charInventory, location);
	return 1;
}

bool EnvironmentItem::changeEnv(List* charInventory){	//searching should be done by handling function;
	int location = find(roomInventory, &this);
	removeNth(roomInventory, location);
	return 1;
}