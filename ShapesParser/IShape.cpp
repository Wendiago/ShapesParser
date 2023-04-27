#include "IShape.h"

string IShape::toString()
{
	return "Ishape";
}

ostream& operator<<(ostream& out, shared_ptr<IShape> shape) {
	shape->doPrint(out);
	return out;
}