#pragma once
#include "Message.h"

class IReceivable
{
public:
	virtual bool onMessageReceive(Message* m, IReceivable* author) = 0;
	virtual bool sendMessage(Message* m, IReceivable* author) = 0;
};