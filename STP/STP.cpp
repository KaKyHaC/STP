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

ElementImpl* STP::createBridge(String name,int id)//create 
{
	if (getElementByName(name)!=nullptr)
		return nullptr;

	ElementImpl* e = new ElementImpl(name,id);
	bridges.push_back(e);
	return e;
}

ElementImpl* STP::createLAN(String name)
{
	if (getElementByName(name) != nullptr)
		return nullptr;

	ElementImpl* e = new ElementImpl(name);
	lans.push_back(e);
	return e;
}

bool STP::connectElements(String name1, String name2, int cost)
{
	ElementImpl* e1 = getElementByName(name1);
	ElementImpl* e2 = getElementByName(name2);

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

ElementImpl * STP::getElementByName(String  name)
{
	for (auto e : bridges) {
		if (e->getName() == name)
			return e;
	}
	for (auto e : lans) {
		if (e->getName() == name)
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



