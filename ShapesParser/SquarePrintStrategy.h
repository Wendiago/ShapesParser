#pragma once
#include "Square.h"
#include "IPrintStrategy.h"

class SquarePrintStrategy :public IPrintStrategy {
	void print(const IShape& shape, ostream& out) const override;
};