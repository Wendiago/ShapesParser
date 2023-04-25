#include "TriangleParser.h"

// " a=3, b=6, c=9"
IShape* TriangleParser::parse(stringstream data)
{
	regex dataPat("(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+\\.|\\d+\\.\\d+),(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+\\.|\\d+\\.\\d+),(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+\\.|\\d+\\.\\d+)");
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	IShape* triangle = nullptr;

	string str_data = data.str(); //Rebuild string data from stringstream to check pattern
	if (regex_match(str_data, dataPat))
	{
		string temp;
		getline(data, temp, '=');
	
		getline(data, temp, ',');
		a = stod(temp);

		getline(data, temp, '=');

		getline(data, temp, ',');
		b = stod(temp);

		getline(data, temp, '=');

		getline(data, temp);
		c = stod(temp);

		//Check if 3 edges made up a Triangle or not 
		if (isTriangle(a, b, c))
		{
			triangle = new Triangle(a, b, c);
		}
	}
	return triangle;
}

bool TriangleParser::isTriangle(double a, double b, double c)
{
	if ((a + b) <= c || (a + c) <= b || (b + c) <= a)
	{
		return false;
	}
	return true;
}
