#include "EllipseParser.h"
#include "Ellipse.h"

/// <summary>
/// Check for data validation and parse data of an Ellipse into Ellipse object
/// </summary>
/// <param name="data"></param>
/// <returns>Ellipse object readed from data stream</returns>
shared_ptr<IShape> EllipseParser::parse(stringstream data)
{
	regex dataPattern("(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+\\.|\\d+\\.\\d+),(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+\\.|\\d+\\.\\d+)");
	double major_axis = 0.0;
	double minor_axis = 0.0;
	string dataString = data.str();
	shared_ptr<IShape> ellipse(new Ellipse());
	ellipse = nullptr;

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

		if (major_axis > 0 && minor_axis > 0) {
			ellipse.reset(new Ellipse(major_axis, minor_axis));
		}
	}

	return ellipse;
}

/// <summary>
/// Get an instance of Ellipse Parser
/// </summary>
/// <returns>an instance of Ellipse Parser</returns>
shared_ptr<EllipseParser> EllipseParser::getInstance()
{
	shared_ptr<EllipseParser> ellipseParser(new EllipseParser());
	return ellipseParser;
}
