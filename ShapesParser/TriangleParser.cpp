#include "TriangleParser.h"

/// <summary>
/// Check for data validation and parse data of a Triangle into Triangle object
/// </summary>
/// <param name="data"></param>
/// <returns>Triangle object readed from data stream</returns>
shared_ptr<IShape> TriangleParser::parse(stringstream data)
{
	regex dataPat("(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+\\.|\\d+\\.\\d+),(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+\\.|\\d+\\.\\d+),(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+\\.|\\d+\\.\\d+)");
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	shared_ptr<IShape> triangle(new Triangle());
	triangle = nullptr;

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
			triangle.reset(new Triangle(a, b, c));
		}
	}
	return triangle;
}

/// <summary>
/// Determine if the triangle is valid using Triangle Inequality Theorem
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
/// <returns>true if the triangle is valid, else return false</returns>
bool TriangleParser::isTriangle(double a, double b, double c)
{
	if ((a + b) <= c || (a + c) <= b || (b + c) <= a)
	{
		return false;
	}
	return true;
}
