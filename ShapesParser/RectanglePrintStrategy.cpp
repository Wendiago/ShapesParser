#include "RectanglePrintStrategy.h"

void RectanglePrintStrategy::print(const IShape& shape, ostream& out) const
{
	const auto& rectangle = dynamic_cast<const Rectangle&>(shape);
	//Convert to string for printing out
	stringstream ss;
	ss << fixed << setprecision(2) << rectangle.height();
	string str_height = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << rectangle.width();
	string str_width = ss.str();

	ss.str("");
	ss << fixed << setprecision(1) << rectangle.perimeter();
	string str_peri = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << rectangle.area();
	string str_area = ss.str();

	out << left << setw(15) << " | " + rectangle.type()
		<< left << setw(40) << " | Height =  " + str_height + ", Width = " + str_width
		<< left << setw(25) << " | Perimeter = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}
