#include <sstream>
#include <string>
#include <exception>
#include "SquareParser.h"
#include "Square.h"
using namespace std;

IShape* SquareParser::parse(stringstream data)
{
	double edge = 0.0;
	
	//Extract the value we don't need
	string temp;
	getline(data, temp, '=');

	data >> edge;
	IShape* square = new Square(edge);
	return square;
}
