#pragma once
#include "Message.h"

__interface ICostable
{
	void addCost(int cost);
	int getCost();
};
__interface MarkerPortMessage :public ICostable {};


class Port :public IReceivable
{
public:
	enum Status {
		RootPort//only receive messages
		, DesignatedPort//only send mesasges
		, NondesignatedPort//port without connection
		, DisabledPort//not working port
		, Default//send and receive
	};
private:
	Status status;
	IReceivable *element;
	Port *port;
	int cost;
public:
	Port() {};
	Port(int cost,IReceivable* element,Port* connection);
	Port(int cost,IReceivable* element);

	bool connectTo(Port* port);
	bool setStatus(Status s);


	// Унаследовано через IReceivable
	virtual bool onMessageReceive(MarkerPortMessage * m, IReceivable * author) override;

	virtual bool sendMessage(MarkerPortMessage *m, IReceivable * author) override;

};

