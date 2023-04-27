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
#include "EllipseParser.h"
#include "TriangleParser.h"
#include "ParserFactory.h"
#include "IShapeTextDataProvider.h"

using std::cin, std::cout, std::endl, std::exception;

class IShape;
bool compareShapeArea(const shared_ptr<IShape> a, const shared_ptr<IShape> b) {
	return a->area() < b->area();
}

int main()
{
	//create smart pointers of parser
	shared_ptr<IParser> squareParser(new SquareParser());
	shared_ptr<IParser> rectangleParser(new RectangleParser());
	shared_ptr<IParser> circleParser(new CircleParser());
	shared_ptr<IParser> ellipseParser(new EllipseParser());
	shared_ptr<IParser> triangleParser(new TriangleParser());

	//Register parser of shapes
	ParserFactory factory;
	factory.registerWith("Square", squareParser);
	factory.registerWith("Rectangle", rectangleParser);
	factory.registerWith("Circle", circleParser);
	factory.registerWith("Ellipse", ellipseParser);
	factory.registerWith("Triangle", triangleParser);

	//Read file
	string fileName;
	cout << "Enter file name: ";
	getline(cin, fileName);

	IShapeTextDataProvider reader;
	try
	{
		auto shapes = reader.read(fileName, factory);

		// 
		cout << "Reading " << fileName << "..." << endl;
		cout << "Found " << shapes.size()  << "/" << reader.numberOfShape() << " shapes" << endl;
		cout << endl;

		//
		sort(shapes.begin(), shapes.end(), compareShapeArea);

		for (int i = 0; i < shapes.size(); i++) 
		{
			string index = to_string(i + 1);
			cout << left << setw(4) << "| " + index << shapes[i] << endl;
		}

		//
		cout << endl << "Cannot read " << reader.numberOfShape() - shapes.size() << " shapes" << endl;
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
}