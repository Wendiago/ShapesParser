#include "DetailedPrintStrategy.h"

/// <summary>
/// Print all information of shape
/// </summary>
/// <param name="shape"></param>
/// <param name="out"></param>
void DetailedPrintStrategy::doPrint(const IShape& shape, ostream& out) const
{
	shape.detailedPrint(out);
}
