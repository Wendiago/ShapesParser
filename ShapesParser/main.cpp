#include <iostream>
#include <exception>
#include "SquareParser.h"
#include "RectangleParser.h"
#include "CircleParser.h"
#include "ParserFactory.h"
#include "IShapeTextDataProvider.h"
#include <algorithm>

using std::cin, std::cout, std::endl;

bool compareShapeArea(const IShape* a, const IShape* b) {
	return a->area() < b->area();
}

int main()
{
	//Register parser of shapes
	ParserFactory factory;
	factory.registerWith("Square", new SquareParser());
	factory.registerWith("Rectangle", new RectangleParser());
	factory.registerWith("Circle", new CircleParser());

	//Read file
	string fileName;
	getline(cin, fileName);

	IShapeTextDataProvider reader;
	auto shapes = reader.read(fileName, factory);

	cout << shapes.size() << " shapes found" << endl;
	
	sort(shapes.begin(), shapes.end(), compareShapeArea);

	for (auto s : shapes) {
		cout << s << endl;
	}
}