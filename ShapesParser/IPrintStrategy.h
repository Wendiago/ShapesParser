#pragma once
#include <string>
#include <sstream>
#include "IShape.h"

class IPrintStrategy {
public:
	virtual ~IPrintStrategy() = default;
	virtual void print(const IShape& shape, ostream& out) const = 0;
};