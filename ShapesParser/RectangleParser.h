#pragma once
#include "IParser.h"
#include "IShape.h"
#include <regex>
#include <string>

using std::string;
using std::regex, std::regex_match;

class RectangleParser :public IParser {
private:
	shared_ptr<RectangleParser> instance;
	shared_ptr<IShape> parse(stringstream);
public:
	static shared_ptr<RectangleParser> getInstance();
};