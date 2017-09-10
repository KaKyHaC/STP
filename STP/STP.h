#pragma once
#include"ElementImpl.h"
#include<vector>
#define String std::string
class STP
{
	std::vector<ElementImpl*> bridges;
	std::vector<ElementImpl*> lans;
public:
	STP();
	~STP();

	/**
	*create new Bridge
	*@return created Bridge or nullptr if name already exist
	*/
	ElementImpl* createBridge(String name,int id);

	/**
	*create new LAN
	*@return created Bridge or nullptr if name already exist
	*/
	ElementImpl* createLAN(String name);

	/**
	*connect already existed elements
	*@return true if connected success or false if element not exist
	*/
	bool connectElements(String name1, String name2, int cost);

	bool sendMessageFromAllBridges();
	bool sendMessageFromRootBridge();

	int sizeOfBridges();
	ElementImpl* getBridgeAt(int i);
	ElementImpl* getElementByName(String name);

	int getMaxCostToRootFromBridge();

};

#undef Sting

