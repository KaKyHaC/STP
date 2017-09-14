#include"STP.h"
#include"TextParserSTP .h"
#include"STPfromInput.h"
#include<assert.h>
#include<iostream>

#define FILE "text.txt"
int main(int argc, char** argv) {
	std::string file;

	for (int i = 0; i < argc; i++) {
		std::cout << "argv["<<i<<"]= " << argv[i] << '\n';
	}
	std::cout << "\n\n";

	STP*stp;
	if (argc > 1) {
		file = argv[1];

		TextParserSTP* parser = TextParserSTP::getInstance(file);

		if (parser == nullptr) {
			std::cout << "invalid path: " << file << '\n';
			system("pause");
			return -1;
		}
		parser->parse();
		stp = parser->getSTP();
	}
	else {
		stp = STPfromInput().getSTP();
	}
	stp->sendMessageFromAllBridges();
	std::cout << stp->getInfo();	
	system("pause");
	return 1;
}

#undef FILE