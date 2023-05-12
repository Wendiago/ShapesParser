#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <iomanip>
#include <unordered_map>
#include "IShapeTextDataProvider.h"
#include "IShape.h"
#include "Object.h"
#include "ParserFactory.h"
#include "IPrintStrategy.h"
using std::vector, std::to_string, std::left, std::setw, std::unordered_map;

class VectorIShapes {
private:
	vector<shared_ptr<IShape>> _shapes;
	unordered_map<string, shared_ptr<IPrintStrategy>> _strategies;
private:
	static bool compareShapeArea(const shared_ptr<IShape>, const shared_ptr<IShape>);
public:
	void registerWith(const string& type, shared_ptr<IPrintStrategy> printStrategy);
	shared_ptr<IPrintStrategy> select(string);
	int size() const;
public:
	void getShapes(IShapeTextDataProvider&, ParserFactory, string);
	void sortAreaAscending();
	void display(ostream&);
};