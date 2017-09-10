#include "TextParserSTP .h"

#define BRIDGE "BRIDGE"
#define BRIDGEID  "BridgeId"
#define PORT   "Port"
#define PATHCOST  "PathCost"
#define CONNECTEDTO   "ConnectedTo"
#define LAN    "LAN"


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

bool TextParserSTP::parse()
{
	String curBridge="",curLan = "";
	int curId=0, curCost=0;
	for (auto s : text) {
		int i=s.find('[');
		if ( i>= 0)
			createLinc(curBridge, curId, curLan, curCost);
		processRow(s, curBridge, curId, curLan, curCost);
	}
	return false;
}


void TextParserSTP::readText()
{
	String s;
	while (std::getline(*in,s)) {
		text.push_back(s);
	}
}

void TextParserSTP::createLinc(String bridgeName, int id, String LanName, int cost)
{
	if (bridgeName == "" || LanName == "")
		return;
	stp->createBridge(bridgeName, id);
	stp->createLAN(LanName);
	stp->connectElements(bridgeName, LanName, cost);
}
void TextParserSTP::processRow(String s, String& bridgeName, int& id, String& LanName, int& cost) {
	

	if (s=="" ||isContain(s,PORT))
		return;


	if (isContain(s,BRIDGEID))
		id = getId(s);
	else if (isContain(s, BRIDGE))
		bridgeName = getBridgeName(s);
	else if (isContain(s,PATHCOST))
		cost = getCost(s);
	else if (isContain(s,LAN))
		LanName = getLanName(s);

}

String TextParserSTP::getBridgeName(String s)
{
	String name="",b(BRIDGE);
	int pos = s.find(b);
	for (int i = pos + b.length(); i < s.length(); i++) {
		char c = s.at(i);
		if (c != ' '&&c != '['&&c != ']'&&c != '=')
			name += c;
	}
	return name;
}

int TextParserSTP::getId(String s)
{
	String name = "", b(BRIDGEID);
	int pos = s.find(b);
	for (int i = pos + b.length(); i < s.length(); i++) {
		char c = s.at(i);
		if (c != ' '&&c != '['&&c != ']' &&c != '=')
			name += c;
	}
	return atoi(name.c_str());
}

String TextParserSTP::getLanName(String s)
{
	String name = "", b(LAN);
	int pos = s.find(b);
	for (int i = pos + b.length(); i < s.length(); i++) {
		char c = s.at(i);
		if (c != ' '&&c != '['&&c != ']' &&c!='=')
			name += c;
	}
	return name;
}

int TextParserSTP::getCost(String s)
{
	String name = "", b(PATHCOST);
	int pos = s.find(b);
	for (int i = pos + b.length(); i < s.length(); i++) {
		char c = s.at(i);
		if (c != ' '&&c != '['&&c != ']' &&c != '=')
			name += c;
	}
	return atoi(name.c_str());
}

bool TextParserSTP::isContain(String s, String compare)
{
	
	int pos = s.find(compare);
	if (pos < 0)
		return false;

	bool res = true;
	for (int i = pos,j=0; i < s.length(); i++,j++) {
		char c = s.at(i);
		if (c == ' '&&c== '['&&c == ']'&&c== '=')
			return j == compare.length();
	}
	return true;
}
