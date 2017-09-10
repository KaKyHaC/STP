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

Port* Element::createPort(int cost)
{
	Port* port =new Port(cost, this);
	ports.push_back(port);
	return port;
}

int Element::getPortCount()
{
	return ports.size();
}

Port * Element::getPortAt(int i)
{
	if(i>=ports.size())
		return nullptr;
	Port* res = ports[i];
	return res;
}
