#include "SimplePrintStrategy.h"

void SimplePrintStrategy::doPrint(const IShape& shape, ostream& out) const
{
	shape.simplePrint(out);
}
