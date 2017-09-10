#include"STP.h"
#include"TextParserSTP .h"
#include<assert.h>
#include<iostream>
void main() {
	
	std::ofstream out = std::ofstream("write.txt");
	out << "helllo";
	out.close();
	TextParserSTP* parser = TextParserSTP::getInstance("text.txt");
	parser->parse();
	STP*stp = parser->getSTP();
	stp->sendMessageFromAllBridges();
	std::cout << stp->getMaxCostToRootFromBridge();
	system("pause");
}