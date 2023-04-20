#pragma once
#include "IParser.h"
#include "IShape.h"

class CircleParser :public IParser {
public:
	IShape* parse(stringstream);
};