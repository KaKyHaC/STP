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
		if (e->getMyID == id)
			return e;
	}
	for (auto e : lans) {
		if (e->getMyID == id)
			return e;
	}
	return nullptr;
}

