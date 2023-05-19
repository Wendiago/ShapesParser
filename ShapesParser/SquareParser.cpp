#include "SquareParser.h"
#include "Square.h"

/// <summary>
/// Check for data validation and parse data of an Square into Square object
/// </summary>
/// <param name="data"></param>
/// <returns>Square object readed from data stream</returns>
shared_ptr<IShape> SquareParser::parse(stringstream data)
{
	regex dataPattern("(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+\\.|\\d+\\.\\d+)"); 
	double edge = 0.0;
	string dataString = data.str();
	shared_ptr<IShape> square(new Square());
	square = nullptr;

	//checking the data
	bool checkData = regex_match(dataString, dataPattern);

	if (checkData == true) {
		string temp;
		//Extract the value we don't need
		getline(data, temp, '=');

		getline(data, temp, ',');
		edge = stod(temp);

		if (edge > 0) {
			square.reset(new Square(edge));
		}
	}

	return square;
}

shared_ptr<SquareParser> SquareParser::getInstance()
{
	shared_ptr<SquareParser> squareParser(new SquareParser());
	return squareParser;
}
