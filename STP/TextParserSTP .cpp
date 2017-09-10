#include "TextParserSTP .h"

TextParserSTP::TextParserSTP(std::ifstream* in)
{
	this->in = in;
	readText();
}

TextParserSTP * TextParserSTP::getInstance(String pathToFile)
{
	std::ifstream* in = new std::ifstream();
	in->open(pathToFile);
	if(!in->is_open())
		return nullptr;
	
	return new TextParserSTP(in);
}


void TextParserSTP::readText()
{
	String s;
	while (std::getline(*in,s)) {
		text.push_back(s);
	}
}
