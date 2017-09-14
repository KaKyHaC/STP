#pragma once

/**
* @class Message
* BPDU message to configure network settings
*/
class Message
{
	const int Id;
	int totalCost;
public:
	

	Message(int id);
	Message(int rootId, int costToRoot);
	

	
	inline void addCost(int cost){totalCost += cost; }
	inline int getCost(){return totalCost; }
	inline int getID() {return Id; }
};




