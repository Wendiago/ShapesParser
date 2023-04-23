#include <string>
#include <sstream>
#include "RectangleParser.h"
#include "Rectangle.h"
#include "IShape.h"
using std::exception, std::string;

// Pattern: "Rectangle: w=3, h=4"
IShape* RectangleParser::parse(stringstream data)
{
	double weight = 0.0;
	double height = 0.0;
	
	//Extract the part we don't need
	string temp;
	getline(data, temp, '=');
	string str_weight;
	string str_height;
	try
	{
		getline(data, str_weight, ',');
		weight = stod(str_weight);
	}
	catch (exception ex)
	{
		throw exception("Invalid weight");
	}
	
	//Extract the part we don't need
	getline(data, temp, '=');

	try
	{
		getline(data, str_height, ',');
		height = stod(str_height);
	}
	catch (exception ex)
	{
		throw exception("Invalid height");
	}

	IShape* rectangle = new Rectangle(weight, height);
	return rectangle;
}
