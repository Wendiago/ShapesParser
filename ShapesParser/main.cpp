#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "IShape.h"
#include "Object.h"
#include "IParser.h"
#include "SquareParser.h"
#include "RectangleParser.h"
#include "CircleParser.h"
#include "ParserFactory.h"
using namespace std;

int main()
{
	//Register parser of shapes
	ParserFactory factory;
	factory.registerWith("Square", new SquareParser());
	factory.registerWith("Rectangle", new RectangleParser());
	factory.registerWith("Circle", new CircleParser());

	//Read file
	string fileName;
	getline(cin, fileName);

	vector<IShape*> shapes;

	ifstream reader;
	reader.open(fileName, ios::in);
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
	cout << shapes.size() << " shapes found" << endl;
	for (auto s : shapes)
	{
		cout << s->type() << ", Area: " << s->area() << ", Perimeter: " << s->perimeter() << endl;
	}
}