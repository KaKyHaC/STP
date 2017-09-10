#include "STP.h"

STP::STP()
{
	bridges = std::vector<ElementImpl*>();
	lans = std::vector<ElementImpl*>();
}

STP::~STP()
{
	for (auto e : bridges) {
		delete e;
	}
	for (auto e : lans) {
		delete e;
	}
}

bool STP::createBridge(int id)
{
	if (getElementById(id)!=nullptr)
		return false;

	ElementImpl* e = new ElementImpl(id);
	bridges.push_back(e);
	return true;
}

bool STP::createLAN(int id)
{
	if (getElementById(id) != nullptr)
		return false;

	ElementImpl* e = new ElementImpl(id);
	lans.push_back(e);
	return true;
}

bool STP::connectElements(int id1, int id2, int cost)
{
	ElementImpl* e1 = getElementById(id1);
	ElementImpl* e2 = getElementById(id2);

	if (e1 == nullptr || e2 == nullptr)
		return false;

	Port* p1 = e1->createPort(cost);
	Port* p2 = e2->createPort(cost);

	if (p1 == nullptr || p2 == nullptr)
		return false;

	p1->connectTo(p2);
	return true;
}

bool STP::sendMessageFromAllBridges()
{
	for (auto e : bridges) {
		e->sendMessageToAllFromThis();
	}
	return true;
}

bool STP::sendMessageFromRootBridge()
{
	ElementImpl* root = bridges[0];
	for (auto b : bridges) {
		if (b->getMyID() < root->getMyID())
			root = b;
	}
	root->sendMessageToAllFromThis();
	return true;
}

int STP::sizeOfBridges()
{
	return bridges.size();
}

ElementImpl * STP::getBridgeAt(int i)
{
	if(i>=sizeOfBridges())
		return nullptr;

	return bridges[i];
}

ElementImpl * STP::getElementById(int id)
{
	for (auto e : bridges) {
		if (e->getMyID() == id)
			return e;
	}
	for (auto e : lans) {
		if (e->getMyID() == id)
			return e;
	}
	return nullptr;
}

int STP::getMaxCostToRootFromBridge()
{
	int max=0;
	for (auto p : bridges) {
		int cost = p->getCostToRoot();
		if (cost > max)
			max = cost;
	}
	return max;
}

