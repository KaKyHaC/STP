#pragma once


__interface IReceivable
{
	bool onMessageReceive(Message* m, IReceivable* author);
	bool sendMessage(Message* m, IReceivable* author);
};

class Message
{
	const int Id;
	int totalCost;
public:
	

	Message(int id);
	~Message();

	
	 void addCost(int cost)inline;
	 int getCost()inline;
	 int getID()inline {return Id; };
};

