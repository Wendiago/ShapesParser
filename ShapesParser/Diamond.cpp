#include "Diamond.h"

/// <summary>
/// Initialize a Diamond object with default diagonal p = 1.0, diagonal q = 1.0
/// </summary>
Diamond::Diamond() :_diagonal_p(1.0), _diagonal_q(1.0) {}

/// <summary>
/// Initialize a Diamond object with input diagonal p and diagonal q
/// </summary>
/// <param name="radius"></param>
Diamond::Diamond(double digonal_p, double diagonal_q) : _diagonal_p(digonal_p), _diagonal_q(diagonal_q) {}

/// <summary>
/// Delete Diamond object
/// </summary>
Diamond::~Diamond() {}

/// <summary>
/// Set diagonal p for Diamond object
/// </summary>
/// <param name="radius"></param>
void Diamond::setDiagonalP(double value)
{
	_diagonal_p = value;
}

/// <summary>
/// Set diagonal q for Diamond object
/// </summary>
/// <param name="radius"></param>
void Diamond::setDiagonalQ(double value)
{
	_diagonal_q = value;
}

/// <summary>
/// Get diagonal p from Diamond object
/// </summary>
/// <returns>_diagonal_p</returns>
double Diamond::diagonal_p() const
{
	return _diagonal_p;
}

/// <summary>
/// Get diagonal q from Diamond object
/// </summary>
/// <returns>_diagonal_q</returns>
double Diamond::diagonal_q() const
{
	return _diagonal_q;
}

/// <summary>
/// Get type = "Diamond" from Diamond object
/// </summary>
/// <returns>"Diamond"</returns>
string Diamond::type() const
{
	return "Diamond";
}

/// <summary>
/// Caculate area of Diamond object
/// </summary>
/// <returns>Area = diagonal_p*diagonal_q/2</returns>
double Diamond::area() const
{
	return _diagonal_p * _diagonal_q / 2.0;
}

/// <summary>
/// Calculate circumference of Diamond object
/// </summary>
/// <returns>Circumference = 2*sqrt(diagonal_p^2 + diagonal_q^2)</returns>
double Diamond::perimeter() const
{
	return 2 * sqrt(_diagonal_p * _diagonal_p + _diagonal_q * _diagonal_q);
}

void Diamond::simplePrint(ostream& out) const
{
	out << this->type() << ": Diagonal P = " << this->diagonal_p() << ", Diagonal Q = " << this->diagonal_q();
}

void Diamond::detailedPrint(ostream& out) const
{
	stringstream ss;
	ss << fixed << setprecision(2) << this->diagonal_p();
	string str_diagonal_p = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << this->diagonal_q();
	string str_diagonal_q = ss.str();

	ss.str("");
	ss << fixed << setprecision(1) << this->perimeter();
	string str_peri = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << this->area();
	string str_area = ss.str();

	out << left << setw(15) << " | " + this->type()
		<< left << setw(40) << " | Diagonal p = " + str_diagonal_p + ", Diagonal q = " + str_diagonal_q
		<< left << setw(25) << " | Circumference = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}