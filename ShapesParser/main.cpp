#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "IShape.h"
#include "Object.h"
#include "IParser.h"
#include "SquareParser.h"
#include "RectangleParser.h"
#include "CircleParser.h"
#include "ParserFactory.h"
#include "IShapeTextDataProvider.h"

using std::cin, std::cout, std::endl;

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
	for (auto s : shapes)
	{
		cout << s->type() << ", Area: " << s->area() << ", Perimeter: " << s->perimeter() << endl;
	}
}