#pragma once
#include"Port.h"
__interface IReceivable
{
	bool onMessageReceive(Message* m, IReceivable* author);
	bool sendMessage(Message* m, IReceivable* author);
};

class Message:public MarkerPortMessage
{

public:
	Message();
	~Message();

	// ������������ ����� MarkerPortMessage
	virtual void addCost(int cost) override;
	virtual int getCost() override;
};

