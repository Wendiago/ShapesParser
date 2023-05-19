#pragma once
#include <string>
#include <sstream>
#include "IShape.h"

class IPrintStrategy {
public:
	virtual ~IPrintStrategy() = default;
	virtual void doPrint(const IShape& shape, ostream& out) const = 0;
};