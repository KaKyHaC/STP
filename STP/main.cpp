#include"STP.h"
#include<assert.h>
#include<iostream>
void main() {

	STP stp = STP();
	stp.createBridge(1);
	stp.createBridge(2);
	stp.createBridge(3);

	assert(stp.createBridge(3) == false);

	stp.createLAN(4);
	stp.createLAN(5);
	stp.createLAN(6);

	assert(stp.createLAN(5) == false);

	assert(stp.connectElements(1, 4, 10));
	assert(stp.connectElements(1, 5, 10));
	assert(stp.connectElements(2, 4, 5));
	assert(stp.connectElements(2, 5, 5));
	assert(stp.connectElements(3, 6, 10));
	assert(stp.connectElements(3, 5, 10));

	stp.sendMessageFromAllBridges();
	std::cout << stp.getMaxCostToRoot()<<"- max\n";
	for (int i = 1; i < 7; i++) {
		std::cout << "\nat " <<i;
		std::cout<<" cost to root=" << stp.getElementById(i)->getCostToRoot();
	}
	int i;
	std::cin >> i;
}