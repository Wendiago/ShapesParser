#include "CircleParser.h"
#include "Circle.h"

//Pattern: "Circle: r=5"
IShape* CircleParser::parse(stringstream data)
{
	regex dataPattern("(\\s+|)\\w+(\\s|)=(\\s|)(\\d+|\\d+\\.|\\d+\\.\\d+)");
	double radius = 0.0;
	string dataString = data.str();
	IShape* circle = nullptr;

	//checking the data
	bool checkData = regex_match(dataString, dataPattern);

	if (checkData == true) {
		string temp;
		//Extract the value we don't need
		getline(data, temp, '=');

		getline(data, temp, ',');
		radius = stod(temp);

		circle = new Circle(radius);
	}
	
	return circle;
}
