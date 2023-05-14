#pragma once
#include "Ellipse.h"
#include "IPrintStrategy.h"

class EllipsePrintStrategy :public IPrintStrategy {
	void print(const IShape& shape, ostream& out) const override;
};