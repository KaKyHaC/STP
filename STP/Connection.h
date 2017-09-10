#pragma once
#include"Port.h"

class Connection
{
	class ConnectionReceiver :public IReceivable {
		IReceivable* receiver;
		int cost;
		// Унаследовано через IReceivable
		virtual bool onMessageReceive(ICostable* m) override;
	public:
		ConnectionReceiver(IReceivable* receiver,int cost);
	}*from1to2, *from2to1;
	Port * port1, *port2;
	int cost;
public:
	Connection(Port* port1,Port* port2,int cost);
	~Connection();
};

