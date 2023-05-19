#pragma once
#include "IPrintStrategy.h"

class SimplePrintStrategy : public IPrintStrategy {
public:
	void doPrint(const IShape& shape, ostream& out) const override;
};