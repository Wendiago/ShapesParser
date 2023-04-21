#include "IShape.h"

string IShape::toString()
{
	return "Ishape";
}

ostream& operator<<(ostream& out, IShape* shape) {
	shape->doPrint(out);
	return out;
}