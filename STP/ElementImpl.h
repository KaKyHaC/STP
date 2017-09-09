#pragma once
#include "Element.h"
class ElementImpl:public Element
{
	const int myId;
	struct RootParam {
		int rootId;
		int costToRoot;
		IReceivable* portToRoot;
	}rootParam;
public:
	ElementImpl(int id) :myId(id) {
		rootParam.rootId = myId;
		rootParam.costToRoot = 0;
		rootParam.portToRoot = nullptr;
	};

	inline const int getCostToRoot(){return rootParam.costToRoot; }
	inline const int getMyID(){return myId; }
	inline const int getRootID(){return rootParam.rootId; }

	void sendMessageToAllFromThis();
	void sendMessageToAllFromRoot();
	

	// Унаследовано через Element
	virtual bool onMessageReceive(Message * m, IReceivable * author) override;
	virtual bool sendMessage(Message * m, IReceivable * author) override;
private:

	void tryChangeRootParam(Message *m, IReceivable* author );

};

