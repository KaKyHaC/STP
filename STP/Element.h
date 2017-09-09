#pragma once
#include "Port.h"
#include<vector>
class Element:public IReceivable
{
	std::vector<Port*> ports;
public:
	Element() ;
	~Element();

	bool createPort(int cost);
	int getPortCount();
	Port* getPortAt(int i);
};

