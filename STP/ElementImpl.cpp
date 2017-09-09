#include "ElementImpl.h"

void ElementImpl::sendMessageToAllFromThis()
{
	Message m = Message(myId);
	for (auto p : ports) {
		p->sendMessage(&m,this);
	}
}

void ElementImpl::sendMessageToAllFromRoot()
{
	Message m = Message(rootParam.rootId,rootParam.costToRoot);
	for (auto p : ports) {
		if(p!=rootParam.portToRoot)
			p->sendMessage(&m, this);
	}
}

bool ElementImpl::onMessageReceive(Message * m, IReceivable * author)
{
	tryChangeRootParam(m, author);
	sendMessageToAllFromRoot();
	return true;
}

bool ElementImpl::sendMessage(Message * m, IReceivable * author)
{
	return false;
}

void ElementImpl::tryChangeRootParam(Message * m, IReceivable* author)
{
	int id = m->getID();
	int cost = m->getCost();

	if ( id> rootParam.rootId)
		return;

	if (id == rootParam.rootId) {
		if (cost < rootParam.costToRoot) {
			rootParam.costToRoot = cost;
			rootParam.portToRoot = author;
		}
	}else if (id < rootParam.rootId) {
		rootParam.rootId = id;
		rootParam.costToRoot = cost;
		rootParam.portToRoot = author;
	}
}
