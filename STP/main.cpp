#include"STP.h"
#include"TextParserSTP .h"
#include<assert.h>
#include<iostream>

#define FILE "text.txt"
int main(int argc, char** argv) {
	std::string file;

	for (int i = 0; i < argc; i++) {
		std::cout << "argv["<<i<<"]= " << argv[i] << '\n';
	}
	std::cout << "\n\n";

	if (argc == 2)
		file = argv[1];
	else
		file = FILE;

	TextParserSTP* parser = TextParserSTP::getInstance(file);

	if (parser == nullptr) {
		std::cout << "invalid path: " << file<<'\n';
		system("pause");
		return -1;
	}
	parser->parse();
	STP*stp = parser->getSTP();
	stp->sendMessageFromAllBridges();
	std::cout << stp->getInfo();	
	system("pause");
	return 0;
}

#undef FILE