#include "EllipseParser.h"
#include "Ellipse.h"

// Pattern: "Rectangle: w=3, h=4"
IShape* EllipseParser::parse(stringstream data)
{
	regex dataPattern("(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+.|\\d+.\\d+),(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+.|\\d+.\\d+)");
	double major_axis = 0.0;
	double minor_axis = 0.0;
	string dataString = data.str();
	IShape* ellipse = nullptr;

	//checking the data
	bool checkData = regex_match(dataString, dataPattern);

	if (checkData == true) {
		string temp;
		//Extract the value we don't need
		getline(data, temp, '=');

		getline(data, temp, ',');
		major_axis = stod(temp);

		//Extract the part we don't need
		getline(data, temp, '=');

		getline(data, temp, ',');
		minor_axis = stod(temp);

		ellipse = new Ellipse(major_axis, minor_axis);
	}

	return ellipse;
}
