#pragma once
#include "Element.h"
#include<string>
#define MAXID 999999

class ElementImpl:public Element
{
	const int Id;
	const std::string name;
	struct RootParam {
		int rootId;
		int costToRoot;
		IReceivable* portToRoot;
	}rootParam;
public:
	ElementImpl(std::string name) :Id(MAXID), name(name) {
		rootParam.rootId = Id;
		rootParam.costToRoot = 0;
		rootParam.portToRoot = nullptr;
	};
	ElementImpl(std::string name,int id) :Id(id),name(name) {
		rootParam.rootId = Id;
		rootParam.costToRoot = 0;
		rootParam.portToRoot = nullptr;
	};

	inline const int getCostToRoot(){return rootParam.costToRoot; }
	inline const int getMyID(){return Id; }
	inline const int getRootID(){return rootParam.rootId; }
	inline const std::string getName() { return name; }

	void sendMessageToAllFromThis();
	void sendMessageToAllFromRoot();
	

	// Унаследовано через Element
	virtual bool onMessageReceive(Message * m, IReceivable * author) override;
	virtual bool sendMessage(Message * m, IReceivable * author) override;
private:

	void tryChangeRootParam(Message *m, IReceivable* author );
	bool tryChangeRootPort(IReceivable* newRootPort);
};

#undef MAXID
