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
		if (a > 0 && b > 0 && c > 0 && Triangle::isTriangle(a, b, c))
		{
			triangle.reset(new Triangle(a, b, c));
		}
	}
	return triangle;
}


/// <summary>
/// Get an instance of Triangle Parser
/// </summary>
/// <returns>an instance of Triangle Parser</returns>
shared_ptr<TriangleParser> TriangleParser::getInstance()
{
	shared_ptr<TriangleParser> triangleParser(new TriangleParser());
	return triangleParser;
}


