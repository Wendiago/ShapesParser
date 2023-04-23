#include "CircleParser.h"
#include "IShape.h"
#include "Circle.h"
#include <string>
#include <sstream>

//Pattern: "Circle: r=5"
IShape* CircleParser::parse(stringstream data)
{
	regex checkData("\\w+(\\s|)=(\\s|)(\\d+|\\d+.|\\d+.\\d+)");
	double radius = 0.0;

	bool check = regex_match(data, checkData);

	//Extract the value we don't need
	string temp;
	getline(data, temp, '=');

	data >> radius;

	IShape* circle = new Circle(radius);
	return circle;
}
