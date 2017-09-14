#include "STPfromInput.h"

STP * STPfromInput::initSTP()
{
	stp = new STP();
	char* s = new char;
	std::string bridgeName;
	int val;
	while (true) {
		do {
			std::cout << "Write: 'b' to add new bridge, 'e' to exit\n";
			std::cin >> s;

			if (s[0] == 'e')
				return stp;

		} while (s[0] != 'b');
		do {
			std::cout << "Write unique bridge name =";
			std::cin >> s;
			bridgeName = s;
			std::cout << "Write bridge id =";
			std::cin >> val;
		}while(stp->createBridge(s, val)==nullptr);
		while (true) {
			do {
				std::cout << "Write: 'l' to add new connection with LAN, 'f' to finish this bridge\n";
				std::cin >> s;

			} while (s[0] != 'l'&&s[0] != 'f');
			if (s[0] == 'l') {
				std::cout << "Write LAN name =";
				std::cin >> s;
				std::cout << "Write Path Cost =";
				std::cin >> val;

				stp->createLAN(s);
				stp->connectElements(bridgeName, s, val);
			}
			else
				break;
		}
	}
}
