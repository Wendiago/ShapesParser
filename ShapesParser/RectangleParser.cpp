#include "RectangleParser.h"
#include "Rectangle.h"

// Pattern: "Rectangle: w=3, h=4"
shared_ptr<IShape> RectangleParser::parse(stringstream data)
{
	regex dataPattern("(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+.|\\d+.\\d+),(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+.|\\d+.\\d+)");
	double weight = 0.0;
	double height = 0.0; 	
	string dataString = data.str();
	shared_ptr<IShape> rectangle(new Rectangle());
	rectangle = nullptr;
	
	//checking the data
	bool checkData = regex_match(dataString, dataPattern);

	if (checkData == true) {
		string temp;
		//Extract the value we don't need
		getline(data, temp, '=');

		getline(data, temp, ',');
		weight = stod(temp);

		//Extract the part we don't need
		getline(data, temp, '=');

		getline(data, temp, ',');
		height = stod(temp);

		rectangle.reset(new Rectangle(weight, height));
	}
	
	return rectangle;
}
