#include "SquarePrintStrategy.h"

void SquarePrintStrategy::print(const IShape& shape, ostream& out) const
{
	const auto& square = dynamic_cast<const Square&>(shape);
	//Convert to string for printing out
	stringstream ss;
	ss << fixed << setprecision(2) << square.edge();
	string str_edge = ss.str();

	ss.str("");
	ss << fixed << setprecision(1) << square.perimeter();
	string str_peri = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << square.area();
	string str_area = ss.str();

	out << left << setw(15) << " | " + square.type()
		<< left << setw(40) << " | Edge = " + str_edge
		<< left << setw(25) << " | Perimeter = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}
