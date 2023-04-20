#include <string>
#include <sstream>
#include "RectangleParser.h"
#include "Rectangle.h"
#include "IShape.h"
using namespace std;

// Pattern: "Rectangle: w=3, h=4"
IShape* RectangleParser::parse(stringstream data)
{
	double weight = 0.0;
	double height = 0.0;
	
	//Extract the part we don't need
	string temp;
	getline(data, temp, '=');

	data >> weight; //Store weight

	//Extract the part we don't need
	getline(data, temp, '=');

	data >> height;

	IShape* rectangle = new Rectangle(weight, height);
	return rectangle;
}
