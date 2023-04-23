#include "RectangleParser.h"
#include "Rectangle.h"

// Pattern: "Rectangle: w=3, h=4"
IShape* RectangleParser::parse(stringstream data)
{
	regex checkData("(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+.|\\d+.\\d+),(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+.|\\d+.\\d+)");
	double weight = 0.0;
	double height = 0.0; 	
	string checkS = data.str();
	IShape* rectangle = nullptr;
	
	//checking the data
	bool check = regex_match(checkS, checkData);

	if (check == true) {
		string temp;
		//Extract the value we don't need
		getline(data, temp, '=');

		getline(data, temp, ',');
		weight = stod(temp);

		//Extract the part we don't need
		getline(data, temp, '=');

		getline(data, temp, ',');
		height = stod(temp);

		rectangle = new Rectangle(weight, height);
	}
	
	return rectangle;
}
