#include "IShape.h"

/// <summary>
/// Display IShape
/// </summary>
/// <returns>string IShape</returns>
string IShape::toString()
{
	return "IShape";
}

/// <summary>
/// Display information of a Shape, for inheritance purpose
/// </summary>
/// <param name="out"></param>
/// <param name="shape"></param>
/// <returns>an ostream</returns>
ostream& operator<<(ostream& out, shared_ptr<IShape> shape) {
	shape->doPrint(out);
	return out;
}