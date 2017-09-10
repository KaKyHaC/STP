#pragma once
#include "Message.h"

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
	Port(int cost,IReceivable* element,Port* connection);
	Port(int cost,IReceivable* element);

	bool connectTo(Port* port);
	bool setStatus(Status s);

	IReceivable* getConnectedElement();
	// Унаследовано через IReceivable
	virtual bool onMessageReceive(Message * m, IReceivable * author) override;

	virtual bool sendMessage(Message *m, IReceivable * author) override;

};

