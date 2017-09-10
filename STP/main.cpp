#include"STP.h"
#include"TextParserSTP .h"
#include<assert.h>
#include<iostream>

#define FILE "text.txt"
int main(int argc, char** argv) {
	std::string file;
	if (argc == 2)
		file = argv[1];
	else
		file = FILE;

	TextParserSTP* parser = TextParserSTP::getInstance(file);
	parser->parse();
	STP*stp = parser->getSTP();
	stp->sendMessageFromAllBridges();
	std::cout << stp->getInfo();	
	system("pause");
	return 0;
}

#undef FILE