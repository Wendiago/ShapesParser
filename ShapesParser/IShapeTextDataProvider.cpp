#include "IShapeTextDataProvider.h"

vector<IShape*> IShapeTextDataProvider::read(string input, ParserFactory factory) {
	ifstream reader;
	reader.open(input, ios::in);
	vector<IShape*> shapes;

	if (reader.good())
	{
		//Get number of Shapes
		string numOfShape;
		getline(reader, numOfShape);
		int num = stoi(numOfShape);

		for (int i = 0; i < num; i++)
		{
			string line;
			getline(reader, line);
			stringstream ss(line);

			//Get type of shapes
			string type;
			getline(ss, type, ':');

			//Get data
			string data;
			getline(ss, data);

			//Select parser based on type
			IParser* parser = factory.select(type);
			if (parser != nullptr)
			{
				IShape* shape = parser->parse((stringstream)data); //Parse data to the corresponding parser, return the shape
				shapes.push_back(shape); //Push the shape to the list
			}
		}

		reader.close();
	}

	return shapes;
}