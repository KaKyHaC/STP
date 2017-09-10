#pragma once
#include"STP.h"
#include <iostream>
#include <fstream>
#include<vector>
#define String std::string

class TextParserSTP {
	std::ifstream* in;
	STP* stp=new STP();
	bool isParsed = false;
	std::vector<String> text=std::vector<String>();
	TextParserSTP(std::ifstream*);

public:
	static TextParserSTP* getInstance(String);
	bool parse();
	STP* getSTP();

private :
	void readText();
};