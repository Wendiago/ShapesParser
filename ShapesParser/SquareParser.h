#pragma once
#include "IParser.h"
#include "IShape.h"

class SquareParser :public IParser {
public:
	IShape* parse(stringstream);
};