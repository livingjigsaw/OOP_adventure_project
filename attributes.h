struct attributeList{  //what actions can be done on an object?
	bool edible; 	//eat command
	bool takeable;	//take, pickup
	bool droppable;	// drop, leave, throw
	bool catchable; //can this object catch on  different object (grappling hook)
	bool catcher;  	//can this object catch a catchable object (ie a ledge)
	bool weapon;	//can be used to kill living object, swing command
	bool alive;		//can die
	bool destructible;	//can this item be removed entirely
	int perishible; 	//item destroyed after x turns, 0 for false
};

//this whole file may become turned into keywords