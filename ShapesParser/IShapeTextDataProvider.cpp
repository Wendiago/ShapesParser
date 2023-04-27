#include "IShapeTextDataProvider.h"

IShapeTextDataProvider::IShapeTextDataProvider()
{
	_numberOfShape = 0;
}

int IShapeTextDataProvider::numberOfShape() const
{
	return _numberOfShape;
}

vector<shared_ptr<IShape>> IShapeTextDataProvider::read(string input, ParserFactory factory) {
	ifstream reader;
	reader.open(input, ios::in);
	vector<shared_ptr<IShape>> shapes;

	if (reader.good())
	{
		//Get number of Shapes
		string numOfShape;
		getline(reader, numOfShape);
		_numberOfShape = stoi(numOfShape);
		
		for (int i = 0; i < _numberOfShape; i++)
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
			shared_ptr<IParser> parser = factory.select(type);

			if (parser != nullptr){
				shared_ptr<IShape> shape = parser->parse((stringstream)data); //Parse data to the corresponding parser, return the shape

				if (shape != nullptr) {
					shapes.push_back(shape); //Push the shape to the list
				}
			}
		}
		reader.close();
	}
	else
	{
		throw exception("Invalid file name");
	}

	return shapes;
}