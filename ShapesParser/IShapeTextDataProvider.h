#pragma once
#include "IShape.h"
#include "IParser.h"
#include "ParserFactory.h"
#include "fstream"
#include "sstream"
#include "vector"

using std::vector;
using std::ifstream, std::ios;

class IShapeTextDataProvider {
public:
    static vector<shared_ptr<IShape>> read(string, ParserFactory);
};