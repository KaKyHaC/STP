#include "Element.h"



Element::Element()
{
	ports = std::vector<Port*>();
}


Element::~Element()
{
	for (auto p : ports) {
		delete p;
	}
	ports.clear();
}

bool Element::createPort(int cost)
{
	Port* port =new Port(cost, this);
	ports.push_back(port);
	return true;
}

int Element::getPortCount()
{
	return ports.size();
}

Port * Element::getPortAt(int i)
{
	if(ports.size()<i)
		return nullptr;
	Port* res = ports[i];
	return res;
}
