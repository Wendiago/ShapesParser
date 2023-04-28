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
#include "VectorIShapes.h"

int main()
{
	//Create smart pointers of parser
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
		//Create a vector of shapes and read txt file to the vector
		VectorIShapes shapes;
		shapes.getShapes(reader, factory, fileName);

		//Inform that the file is readed and display number of valid shapes / number of total shapes in txt file
		cout << "Reading " << fileName << "..." << endl;
		cout << "Found " << shapes.size()  << "/" << reader.numberOfShape() << " shapes" << endl;
		cout << endl;

		//Display all information about valid shaped readed from txt file
		shapes.display();

		//Display number of invalid shapes from txt file
		cout << endl << "Cannot read " << reader.numberOfShape() - shapes.size() << " shapes" << endl;
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
}