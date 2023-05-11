#include "CirclePrintStrategy.h"

void CirclePrintStrategy::print(const IShape& shape, ostream& out) const
{
	const auto& circle = dynamic_cast<const Circle&>(shape);
	stringstream ss;
	ss << fixed << setprecision(2) << circle.radius();
	string str_radius = ss.str();

	ss.str("");
	ss << fixed << setprecision(1) << circle.perimeter();
	string str_peri = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << circle.area();
	string str_area = ss.str();

	out << left << setw(15) << " | " + circle.type()
		<< left << setw(40) << " | Radius = " + str_radius
		<< left << setw(25) << " | Circumference = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}
