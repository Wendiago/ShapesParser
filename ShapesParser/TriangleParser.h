#pragma once
#include "IParser.h"
#include "IShape.h"
#include "Triangle.h"
#include <regex>
#include <string>
using namespace std;

class TriangleParser :public IParser {
public:
	shared_ptr<IShape> parse(stringstream);
public:
	static bool isTriangle(double, double, double);
};