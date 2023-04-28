#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <iomanip>
#include "IShapeTextDataProvider.h"
#include "IShape.h"
#include "Object.h"
#include "ParserFactory.h"
using std::vector, std::to_string, std::left, std::setw;

class VectorIShapes {
private:
	vector<shared_ptr<IShape>> _shapes;
private:
	static bool compareShapeArea(const shared_ptr<IShape>, const shared_ptr<IShape>);
public:
	VectorIShapes() = default;
	int size() const;
public:
	void getShapes(IShapeTextDataProvider&, ParserFactory, string);
	void sortShapes();
	void display();
};