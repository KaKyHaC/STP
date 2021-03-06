#pragma once
#include"Message.h"
#include"Port.h"
#include"IReceivable.h"
#include<vector>

/**
* @class Element
* the base element of ST
* */
class Element:public IReceivable
{
protected:
	std::vector<Port*> ports;
public:
	Element() ;
	~Element();

	Port* createPort(int cost);
	int getPortCount();
	Port* getPortAt(int i);
};

