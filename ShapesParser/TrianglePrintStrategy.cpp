#include "TrianglePrintStrategy.h"

void TrianglePrintStrategy::print(const IShape& shape, ostream& out) const
{
	const auto& triangle = dynamic_cast<const Triangle&>(shape);
	//Convert to string for printing out
	stringstream ss;
	ss << fixed << setprecision(2) << triangle.a();
	string str_a = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << triangle.b();
	string str_b = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << triangle.c();
	string str_c = ss.str();

	ss.str("");
	ss << fixed << setprecision(1) << triangle.perimeter();
	string str_peri = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << triangle.area();
	string str_area = ss.str();

	out << left << setw(15) << " | " + triangle.type()
		<< left << setw(40) << " | a = " + str_a + ", b = " + str_b + ", c = " + str_c
		<< left << setw(25) << " | Circumference = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}
