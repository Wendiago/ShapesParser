#include "CircleParser.h"
#include "Circle.h"

//Pattern: "Circle: r=5"
IShape* CircleParser::parse(stringstream data)
{
	regex checkData("(\\s+|)\\w+(\\s|)=(\\s|)(\\d+|\\d+.|\\d+.\\d+)");
	double radius = 0.0;
	string checkS = data.str();
	IShape* circle = nullptr;

	//checking the data
	bool check = regex_match(checkS, checkData);

	if (check == true) {
		string temp;
		//Extract the value we don't need
		getline(data, temp, '=');

		getline(data, temp, ',');
		radius = stod(temp);

		circle = new Circle(radius);
	}
	
	return circle;
}
