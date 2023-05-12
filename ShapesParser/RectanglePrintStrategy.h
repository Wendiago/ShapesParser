#pragma once
#include "Rectangle.h"
#include "IPrintStrategy.h"

class RectanglePrintStrategy :public IPrintStrategy {
	void print(const IShape& shape, ostream& out) const override;
};