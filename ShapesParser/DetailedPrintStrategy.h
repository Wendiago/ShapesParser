#pragma once
#include "IPrintStrategy.h"

class DetailedPrintStrategy : public IPrintStrategy {
public:
	void doPrint(const IShape& shape, ostream& out) const override;
};