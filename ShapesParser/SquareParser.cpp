#include "SquareParser.h"
#include "Square.h"

IShape* SquareParser::parse(stringstream data)
{
	regex dataPattern("(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+.|\\d+.\\d+)"); 
	double edge = 0.0;
	string dataString = data.str();
	IShape* square = nullptr;

	//checking the data
	bool checkData = regex_match(dataString, dataPattern);

	if (checkData == true) {
		string temp;
		//Extract the value we don't need
		getline(data, temp, '=');

		getline(data, temp, ',');
		edge = stod(temp);

		square = new Square(edge);
	}

	return square;
}
