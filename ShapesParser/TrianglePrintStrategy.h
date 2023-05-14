#pragma once
#include "Triangle.h"
#include "IPrintStrategy.h"

class TrianglePrintStrategy :public IPrintStrategy {
	void print(const IShape& shape, ostream& out) const override;
};