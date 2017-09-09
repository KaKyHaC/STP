#pragma once
#include"ElementImpl.h"
#include<vector>
class STP
{
	std::vector<ElementImpl*> bridges;
	std::vector<ElementImpl*> lans;
public:
	STP();
	~STP();

	//bool createElement(int id);
	bool createBridge(int id);
	bool createLAN(int id);
	bool connectElements(int id1, int id2, int cost);

	bool sendMessageFromAllBridges();

	int sizeOfBridges();
	ElementImpl* getBridgeAt(int i);
	int getMaxCostToRoot();
};

