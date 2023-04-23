#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "IShape.h"
#include "Object.h"
#include "IParser.h"
#include "SquareParser.h"
#include "RectangleParser.h"
#include "CircleParser.h"
#include "TriangleParser.h"
#include "ParserFactory.h"
#include "IShapeTextDataProvider.h"

using std::cin, std::cout, std::endl, std::exception;

class IShape;
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
	factory.registerWith("Triangle", new TriangleParser());
	//Read file
	string fileName;
	getline(cin, fileName);

	IShapeTextDataProvider reader;
	try
	{
		auto shapes = reader.read(fileName, factory);
		cout << shapes.size() << " shapes found" << endl;

		sort(shapes.begin(), shapes.end(), compareShapeArea);

		for (auto s : shapes) {
			cout << s << endl;
		}
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
}