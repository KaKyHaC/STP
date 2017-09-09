#pragma once
#include"Message.h"
#include<vector>
class Element:public IReceivable
{
	std::vector<Port*> ports;
public:
	Element() ;
	~Element();

	Port* createPort(int cost);
	int getPortCount();
	Port* getPortAt(int i);
};

