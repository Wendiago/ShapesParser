#include "DetailedPrintStrategy.h"

void DetailedPrintStrategy::doPrint(const IShape& shape, ostream& out) const
{
	shape.detailedPrint(out);
}
