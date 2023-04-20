#include "CircleParser.h"
#include "IShape.h"
#include "Circle.h"

//Pattern: "Circle: r=5"
IShape* CircleParser::parse(stringstream data)
{
	double radius = 0.0;

	string temp;
	getline(data, temp, '=');

	data >> radius;

	IShape* circle = new Circle(radius);
	return circle;
}
