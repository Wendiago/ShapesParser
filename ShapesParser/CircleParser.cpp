#include "CircleParser.h"
#include "IShape.h"
#include "Circle.h"
#include <exception>
#include <string>
using std::exception, std::string;

//Pattern: "Circle: r=5"
IShape* CircleParser::parse(stringstream data)
{
	regex checkData("\\w+(\\s|)=(\\s|)(\\d+|\\d+.|\\d+.\\d+)");
	double radius = 0.0;

	bool check = regex_match(data, checkData);

	//Extract the value we don't need
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
