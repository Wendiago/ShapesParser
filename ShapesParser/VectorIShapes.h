#pragma once
#include <vector>
#include "IShape.h"
#include "Object.h"

using std::vector;

class VectorIShapes {
public:
	vector<IShape*> shapes;
};