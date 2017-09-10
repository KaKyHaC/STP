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
	~TextParserSTP()
	{
		delete stp;
	}
	static TextParserSTP* getInstance(String);
	bool parse();
	inline STP* getSTP() {
		return stp;
	};

private :
	void readText();
	void createLinc(String bridgeName, int id, String LanName, int cost);
	void TextParserSTP::processRow(String s, String& bridgeName, int& id, String& LanName, int& cost);

	String getBridgeName(String s);
	int getId(String s);
	String getLanName(String s);
	int getCost(String s);

	bool isContain(String s, String compare);
	bool isSpliter(char c);
};