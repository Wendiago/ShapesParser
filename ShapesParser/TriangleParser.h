#pragma once
#include "IParser.h"
#include "IShape.h"
#include "Triangle.h"
#include <regex>
#include <string>
using namespace std;

class TriangleParser :public IParser {
private:
	shared_ptr<TriangleParser> instance;
	shared_ptr<IShape> parse(stringstream);
public:
	static shared_ptr<TriangleParser> getInstance();
};