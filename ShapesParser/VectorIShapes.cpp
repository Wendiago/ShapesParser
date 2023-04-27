#include "VectorIShapes.h"

bool VectorIShapes::compareShapeArea(const shared_ptr<IShape> a, const shared_ptr<IShape> b)
{
	return a->area() < b->area();
}

int VectorIShapes::size() const
{
	return _shapes.size();
}

void VectorIShapes::getShapes(IShapeTextDataProvider& reader, ParserFactory factory, string fileName)
{
	_shapes = reader.read(fileName, factory);
}

void VectorIShapes::sortShapes()
{
	sort(_shapes.begin(), _shapes.end(), compareShapeArea);
}

void VectorIShapes::display()
{
	for (int i = 0; i < _shapes.size(); i++)
	{
		string index = to_string(i + 1);
		cout << left << setw(4) << "| " + index << _shapes[i] << endl;
	}
}
