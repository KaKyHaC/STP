#pragma once
#include "Element.h"
class Bridge:public Element
{
	const int myId;
	int rootId;
	int costToRoot;
public:
	Bridge(int id) :myId(id) {
		rootId = myId;
		costToRoot = 0;
	};

	const int getCostToRoot()inline{return costToRoot; };
	const int getMyID()inline{return myId; };
	const int getRootID()inline{return rootId; };

	void sendMessageToAll();


private:
	// Унаследовано через Element
	virtual bool onMessageReceive(Message * m, IReceivable * author) override;
	virtual bool sendMessage(Message * m, IReceivable * author) override;

	void 

};

