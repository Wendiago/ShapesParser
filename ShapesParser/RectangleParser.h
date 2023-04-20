#pragma once
#include "IParser.h"
#include "IShape.h"

class RectangleParser :public IParser {
public:
	IShape* parse(stringstream);
};