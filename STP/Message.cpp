#include "Message.h"



Message::Message(int id):Id(id)
{
	totalCost = 0;
}

Message::Message(int rootId, int costToRoot):Id(rootId), totalCost(costToRoot){}
