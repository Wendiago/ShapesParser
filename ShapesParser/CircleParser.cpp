#include "CircleParser.h"
#include "IShape.h"
#include "Circle.h"
#include <exception>
#include <string>
using std::exception, std::string;

//Pattern: "Circle: r=5"
IShape* CircleParser::parse(stringstream data)
{
	double radius = 0.0;

	string temp;
	getline(data, temp, '=');
	string str_Radius;
	try
	{
		getline(data, str_Radius, ',');
		radius = stod(str_Radius);
	}
	catch (exception e)
	{
		throw exception("Invalid radius");
	}

	IShape* circle = new Circle(radius);
	return circle;
}
