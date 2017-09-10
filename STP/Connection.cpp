#include "Connection.h"

Connection::Connection(Port * port1, Port * port2, int cost)
{
	this->cost = cost;
	from1to2 =new  ConnectionReceiver(port2, cost);
	from2to1 =new ConnectionReceiver(port1, cost);
	port1->connectTo(from1to2);
	port2->connectTo(from2to1);
}

Connection::~Connection()
{
}

bool Connection::ConnectionReceiver::onMessageReceive(ICostable* m)
{
	m->addCost(cost);
	return this->receiver->onMessageReceive(m);
}

Connection::ConnectionReceiver::ConnectionReceiver(IReceivable * receiver, int cost)
{
	this->receiver = receiver;
	this->cost = cost;
}
