#pragma once
#include "IParser.h"
#include "IShape.h"
#include <regex>
#include <string>

using std::string;
using std::regex, std::regex_match;

class DiamondParser :public IParser {
private:
	shared_ptr<DiamondParser> instance;
	shared_ptr<IShape> parse(stringstream);
public:
	static shared_ptr<DiamondParser> getInstance();
};