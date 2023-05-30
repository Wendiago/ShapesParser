#include "SimplePrintStrategy.h"

/// <summary>
/// Print shape with simple method
/// </summary>
/// <param name="shape"></param>
/// <param name="out"></param>
void SimplePrintStrategy::doPrint(const IShape& shape, ostream& out) const
{
	shape.simplePrint(out);
}
