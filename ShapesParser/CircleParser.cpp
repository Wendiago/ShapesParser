#include "CircleParser.h"
#include "Circle.h"

//Pattern: "Circle: r=5"
shared_ptr<IShape> CircleParser::parse(stringstream data)
{
	regex dataPattern("(\\s+|)\\w+(\\s|)=(\\s|)(\\d+|\\d+.|\\d+.\\d+)");
	double radius = 0.0;
	string dataString = data.str();
	shared_ptr<IShape> circle(new Circle());
	circle = nullptr;

	//checking the data
	bool checkData = regex_match(dataString, dataPattern);

	if (checkData == true) {
		string temp;
		//Extract the value we don't need
		getline(data, temp, '=');

		getline(data, temp, ',');
		radius = stod(temp);

		circle.reset(new Circle(radius));
	}
	
	return circle;
}
