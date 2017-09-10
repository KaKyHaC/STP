#include "ElementImpl.h"

void ElementImpl::sendMessageToAllFromThis()
{
	for (auto p : ports) {
		Message m = Message(Id);
		p->sendMessage(&m,this);
	}
}

void ElementImpl::sendMessageToAllFromRoot()
{
	for (auto p : ports) {
		if (p != rootParam.portToRoot)
		{
			Message m = Message(rootParam.rootId, rootParam.costToRoot);
			p->sendMessage(&m, this);
		}
	}
}



bool ElementImpl::onMessageReceive(Message * m, IReceivable * author)
{
	tryChangeRootParam(m, author);
	//sendMessageToAllFromRoot();
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
			tryChangeRootPort(author);
			sendMessageToAllFromRoot();//new
		}
	}else if (id < rootParam.rootId) {
		rootParam.rootId = id;
		rootParam.costToRoot = cost;
		tryChangeRootPort(author);
		sendMessageToAllFromRoot();//new 
	}
}

bool ElementImpl::tryChangeRootPort(IReceivable * newRootPort)
{
	if (rootParam.portToRoot != nullptr) {
		if (rootParam.portToRoot != newRootPort) {
			for (auto p : ports) {
				if (p == rootParam.portToRoot) {
					p->setStatus(Port::Status::Default);
					break;
				}
			}
		}
	}
	rootParam.portToRoot = newRootPort;
	for (auto p : ports) {
		if (p == rootParam.portToRoot) {
			p->setStatus(Port::Status::RootPort);
			break;
		}
	}
	return true;
}


