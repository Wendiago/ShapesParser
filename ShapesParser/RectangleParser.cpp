#include "RectangleParser.h"
#include "Rectangle.h"

/// <summary>
/// Check for data validation and parse data of a Rectangle into Rectangle object
/// </summary>
/// <param name="data"></param>
/// <returns>Rectangle object readed from data stream</returns>
shared_ptr<IShape> RectangleParser::parse(stringstream data)
{
	regex dataPattern("(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+\\.|\\d+\\.\\d+),(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+\\.|\\d+\\.\\d+)");
	double width = 0.0;
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
		width = stod(temp);

		//Extract the part we don't need
		getline(data, temp, '=');

		getline(data, temp, ',');
		height = stod(temp);

		if (width > 0 && height > 0) {
			rectangle.reset(new Rectangle(width, height));
		}
	}
	
	return rectangle;
}

/// <summary>
/// Get an instance of Rectangle Parser
/// </summary>
/// <returns>an instance of Rectangle Parser</returns>
shared_ptr<RectangleParser> RectangleParser::getInstance()
{
	shared_ptr<RectangleParser> rectangleParser(new RectangleParser());
	return rectangleParser;
}
