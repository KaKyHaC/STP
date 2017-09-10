#include"STP.h"
#include<assert.h>
#include<iostream>
void main() {

	STP stp = STP();
	stp.createBridge("1",1);
	stp.createBridge("2",2);
	stp.createBridge("3",3);

	assert(stp.createBridge("3",5) == nullptr);

	stp.createLAN("4");
	stp.createLAN("5");
	stp.createLAN("6");

	assert(stp.createLAN("5") == nullptr);

	assert(stp.connectElements("1", "4", 10));
	assert(stp.connectElements("1", "5", 10));
	assert(stp.connectElements("2", "4", 5));
	assert(stp.connectElements("2", "5", 5));
	assert(stp.connectElements("3", "6", 10));
	assert(stp.connectElements("3", "5", 10));

	stp.sendMessageFromRootBridge();

	std::cout << stp.getMaxCostToRootFromBridge()<<"- max\n";
	for (int i = 1; i < 7; i++) {
		std::cout << "\nat " <<i;
		char* buf = new char;
		itoa(i, buf, 10);
		std::string s = std::string(buf);
		std::cout<<" cost to root=" << stp.getElementByName(s)->getCostToRoot();
	}
	std::cout << "\n\n";
	system("pause");
}