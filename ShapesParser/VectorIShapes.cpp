#include "VectorIShapes.h"

/// <summary>
/// Compare 2 shapes of base on their Area
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns>return true if the area of the first shape is less than that of the second shape </returns>
bool VectorIShapes::compareShapeArea(const shared_ptr<IShape> a, const shared_ptr<IShape> b)
{
	return a->area() < b->area();
}

void VectorIShapes::registerWith(const string& type, shared_ptr<IPrintStrategy> printStrategy)
{
	_strategies.insert({type, printStrategy});
}

shared_ptr<IPrintStrategy> VectorIShapes::select(string type)
{
	shared_ptr<IPrintStrategy> strategy = nullptr;
	if (_strategies.contains(type))
	{
		strategy = _strategies[type];
	}
	return strategy;
}

/// <summary>
/// Get the number of shapes stored in vector 
/// </summary>
/// <returns></returns>
int VectorIShapes::size() const
{
	return _shapes.size();
}

/// <summary>
/// Store shapes readed from a file into vector of shapes
/// </summary>
/// <param name="reader"></param>
/// <param name="factory"></param>
/// <param name="fileName"></param>
void VectorIShapes::getShapes(IShapeTextDataProvider& reader, ParserFactory factory, string fileName)
{
	_shapes = reader.read(fileName, factory);
}

/// <summary>
/// Sort shapes bases on their area ascendingly
/// </summary>
void VectorIShapes::sortAreaAscending()
{
	sort(_shapes.begin(), _shapes.end(), compareShapeArea);
}

/// <summary>
/// Display the information of shapes stored in the vector
/// </summary>
void VectorIShapes::display(ostream& out)
{
	for (int i = 0; i < _shapes.size(); i++)
	{
		string index = to_string(i + 1);
		cout << left << setw(4) << "| " + index;
		shared_ptr<IPrintStrategy> strategy = select(_shapes[i]->type());
		strategy->print(*_shapes[i], out);
		out << endl;
	}
}