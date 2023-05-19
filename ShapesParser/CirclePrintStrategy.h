#pragma once
#include "Circle.h"
#include "IPrintStrategy.h"

class CirclePrintStrategy :public IPrintStrategy {
private:
	
	void print(const IShape& shape, ostream& out) const override;
};