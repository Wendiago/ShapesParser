#pragma once
#include "Object.h"
#include "IShape.h"

class IParser :public Object {
public:
	virtual IShape* parse(stringstream) = 0;
	string toString();
};