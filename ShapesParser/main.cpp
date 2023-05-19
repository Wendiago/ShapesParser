#include "IShape.h"
#include "Object.h"
#include "IParser.h"
#include "SquareParser.h"
#include "RectangleParser.h"
#include "CircleParser.h"
#include "EllipseParser.h"
#include "TriangleParser.h"
#include "DiamondParser.h"
#include "ParserFactory.h"
#include "IShapeTextDataProvider.h"
#include "VectorIShapes.h"
#include "IPrintStrategy.h"

int main()
{
	//Register parser of shapes
	ParserFactory factory;
	factory.registerWith("Square", SquareParser::getInstance());
	factory.registerWith("Rectangle", RectangleParser::getInstance());
	factory.registerWith("Circle", CircleParser::getInstance());
	factory.registerWith("Ellipse", EllipseParser::getInstance());
	factory.registerWith("Triangle", TriangleParser::getInstance());
	factory.registerWith("Diamond", DiamondParser::getInstance());

	//Read file
	string fileName;
	cout << "Enter file name: ";
	getline(cin, fileName);

	IShapeTextDataProvider reader;
	try
	{
		//Create a vector of shapes and read txt file to the vector
		VectorIShapes shapes;
		shapes.getShapes(reader, factory, fileName);

		//Inform that the file is readed and display number of valid shapes / number of total shapes in txt file
		cout << "Reading " << fileName << "..." << endl;
		cout << "Found " << shapes.size() << "/" << reader.numberOfShape() << " shapes" << endl;

		//Display simple reading information about valid shaped readed from txt file
		shapes.simpleDisplay(cout);

		//Display number of invalid shapes from txt file
		cout << endl << "Cannot read " << reader.numberOfShape() - shapes.size() << " shapes" << endl;
		cout << endl;

		//Sorting all shapes in ascending order of areas
		shapes.sortAreaAscending();

		//Display all information about valid shaped readed from txt file
		cout << "After sorting all shapes in ascending order of areas:" << endl << endl;
		shapes.detailedDisplay(cout);

	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
}