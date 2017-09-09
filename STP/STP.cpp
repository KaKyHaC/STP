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
	ElementImpl* e = new ElementImpl(id);
	bridges.push_back(e);
	return true;
}

bool STP::createLAN(int id)
{
	ElementImpl* e = new ElementImpl(id);
	lans.push_back(e);
	return true;
}
