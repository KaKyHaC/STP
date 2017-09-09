#pragma once


__interface IReceivable
{
	bool onMessageReceive(Message* m, IReceivable* author);
	bool sendMessage(Message* m, IReceivable* author);
};

class Message
{
	
	int totalCost;
public:
	const int Id;

	Message(int id);
	~Message();

	
	virtual void addCost(int cost) ;
	virtual int getCost() ;
};

