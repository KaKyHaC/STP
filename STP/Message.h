#pragma once
#include"Port.h"
class Message:public MarkerPortMessage
{

public:
	Message();
	~Message();

	// ������������ ����� MarkerPortMessage
	virtual void addCost(int cost) override;
	virtual int getCost() override;
};

