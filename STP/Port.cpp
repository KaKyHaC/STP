#include "Port.h"
#define null nullptr



Port::Port(int cost, IReceivable * element, Port * connection)
{
	this->cost = cost;
	this->element = element;
	this->port = connection;
	this->status = Default;
}

Port::Port(int cost, IReceivable * element)
{
	this->cost = cost;
	this->element = element;
	this->port = null;
	this->status = Status::NondesignatedPort;
}

bool Port::connectTo(Port * port)
{
	if(port==null)
		return false;

	this->port = port;
	port->port = this;

	setStatus(Default);

	return true;
}

bool Port::setStatus(Status s)
{
	this->status = s;
	if (port != null) {
		if (s == Status::RootPort)
			port->status = Status::DesignatedPort;
		else if (s == Status::DesignatedPort)
			port->status = Status::RootPort;
		else if (s == Status::Default)
			port->status = Status::Default;
	}
	return true;
}

IReceivable * Port::getConnectedElement()
{
	if(port==nullptr)
		return nullptr;
	return port->element;
}

bool Port::onMessageReceive(Message * m, IReceivable * author)
{
	if(element!=null)
		if(status==Status::Default||status==Status::RootPort )
			return element->onMessageReceive(m,this);
	return false;
}

bool Port::sendMessage(Message *m, IReceivable * author)
{
	if(port!=null)
		if (status == Default || status == Status::DesignatedPort)
		{
			m->addCost(cost);
			return port->onMessageReceive(m, this);
		}
	return false;
}
#undef null