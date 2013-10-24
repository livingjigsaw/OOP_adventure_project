#include"1.h"

// items implmentation
using namespace std;

Item::Item(string n){
	name(n);
}

bool InventoryItem::take(List<Item*>* roomInventory, List<Item*>* charInventory){
	InventoryItem* now = this;
	append(*charInventory, (Item*)now);
	int location = find(*roomInventory, (Item*)now);
	removeNth(*roomInventory, location);
	return 1;
}
	
bool InventoryItem::drop(List<Item*>* roomInventory, List<Item*>* charInventory){
	InventoryItem* now = this;
	append(*roomInventory,(Item*)now);
	int location = find(*charInventory, (Item*)now);
	removeNth(*charInventory, location);
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

bool EnvironmentItem::changeEnv(List<Item*>* roomInventory){	//searching should be done by handling function;
	EnvironmentItem* now=this;
	int location = find(*roomInventory,(Item*)now);
	removeNth(*roomInventory, location);
	return 1;
}