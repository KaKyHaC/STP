#pragma once
#include"STP.h"
#include <iostream>

class STPfromInput {
	STP* stp=initSTP();


	STP* initSTP();
public:
	inline STP* getSTP() { return stp; }
};