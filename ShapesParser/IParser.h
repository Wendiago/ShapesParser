#pragma once
#include "Object.h"
#include "IShape.h"
#include "sstream"
#include <memory>

using std::shared_ptr, std::make_shared;
using std::stringstream;

class IParser :public Object {
public:
	virtual shared_ptr<IShape> parse(stringstream) = 0;
	string toString();
};