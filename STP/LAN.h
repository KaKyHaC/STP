#pragma once
#include "Element.h"
#include <string>
class LAN :public Element
{
public:
	const std::string Name;
	LAN(std::string name):Name(name) {	};
};

