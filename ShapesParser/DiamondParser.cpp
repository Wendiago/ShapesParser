#include "DiamondParser.h"
#include "Diamond.h"

/// <summary>
/// Check for data validation and parse data of an Diamond into Diamond object
/// </summary>
/// <param name="data"></param>
/// <returns>Diamond object readed from data stream</returns>
shared_ptr<IShape> DiamondParser::parse(stringstream data)
{
	regex dataPattern("(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+\\.|\\d+\\.\\d+),(\\s+|)\\w+(\\s+|)=(\\s+|)(\\d+|\\d+\\.|\\d+\\.\\d+)");
	double diagonal_p = 0.0;
	double diagonal_q = 0.0;
	string dataString = data.str();
	shared_ptr<IShape> diamond(new Diamond());
	diamond = nullptr;

	//checking the data
	bool checkData = regex_match(dataString, dataPattern);

	if (checkData == true) {
		string temp;
		//Extract the value we don't need
		getline(data, temp, '=');

		getline(data, temp, ',');
		diagonal_p = stod(temp);

		//Extract the part we don't need
		getline(data, temp, '=');

		getline(data, temp, ',');
		diagonal_q = stod(temp);

		if (diagonal_p > 0 && diagonal_q > 0) {
			diamond.reset(new Diamond(diagonal_p, diagonal_q));
		}
	}

	return diamond;
}

shared_ptr<DiamondParser> DiamondParser::getInstance()
{
	shared_ptr<DiamondParser> diamondParser(new DiamondParser());
	return diamondParser;
}
