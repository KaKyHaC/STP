#pragma once
#include"STP.h"
#include <iostream>
#include <fstream>
#include<vector>
#define String std::string


/**
* @class TextParserSTP
* Class for creating a STP implementation from a file
* @note creation through factory method
*/
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

	/**
	*create instance from file
	*@return nullptr if file can't read
	*/
	static TextParserSTP* getInstance(String);

	/**
	*parse STP from readed file
	*/
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