#pragma once


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

__interface IReceivable
{
	bool onMessageReceive(Message* m, IReceivable* author);
	bool sendMessage(Message* m, IReceivable* author);
};


