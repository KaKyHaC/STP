#include "Message.h"



Message::Message(int id):Id(id)
{
	totalCost = 0;
}

Message::~Message()
{
}

void Message::addCost(int cost)
{
	totalCost += cost;
}

int Message::getCost()
{
	return totalCost;
}
