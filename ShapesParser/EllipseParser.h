#pragma once
#include "IParser.h"
#include "IShape.h"
#include <regex>
#include <string>

using std::string;
using std::regex, std::regex_match;

class EllipseParser :public IParser {
public:
	shared_ptr<IShape> parse(stringstream);
};