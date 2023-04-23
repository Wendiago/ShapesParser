#pragma once
#include "IParser.h"
#include "IShape.h"
#include <regex>

using std::regex, std::regex_match;

class RectangleParser :public IParser {
public:
	IShape* parse(stringstream);
};