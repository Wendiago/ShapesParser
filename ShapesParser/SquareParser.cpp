#include <sstream>
#include <string>
#include <exception>
#include "SquareParser.h"
#include "Square.h"
using std::exception, std::string;

IShape* SquareParser::parse(stringstream data)
{
	double edge = 0.0;
	
	IShape* square = nullptr;
	//Extract the value we don't need
	string temp;
	getline(data, temp, '=');

	string str_Edge;
	try
	{
		getline(data, str_Edge);
		edge = stod(str_Edge);
	}
	catch (exception ex)
	{
		throw exception("Invalid edge");
	}
	square = new Square(edge);
	return square;
}
