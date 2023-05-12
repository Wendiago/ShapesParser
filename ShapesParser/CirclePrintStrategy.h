#pragma once
#include "Circle.h"
#include "IPrintStrategy.h"

class CirclePrintStrategy :public IPrintStrategy {
	void print(const IShape& shape, ostream& out) const override;
};