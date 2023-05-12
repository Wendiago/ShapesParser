#include "EllipsePrintStrategy.h"

void EllipsePrintStrategy::print(const IShape& shape, ostream& out) const
{
	const auto& ellipse = dynamic_cast<const Ellipse&>(shape);
	stringstream ss;
	ss << fixed << setprecision(2) << ellipse.major_axis();
	string str_major = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << ellipse.minor_axis();
	string str_minor = ss.str();

	ss.str("");
	ss << fixed << setprecision(1) << ellipse.perimeter();
	string str_peri = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << ellipse.area();
	string str_area = ss.str();


	out << left << setw(15) << " | " + ellipse.type()
		<< left << setw(40) << " | Major Axis = " + str_major + ", Minor Axis = " + str_minor
		<< left << setw(25) << " | Circumference = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}
