#pragma once
#include "IShape.h"
#include "IParser.h"
#include "ParserFactory.h"
#include "fstream"
#include "sstream"
#include "vector"
#include <iostream>
#include <exception>

using std::vector;
using std::ifstream, std::ios;
using std::cin, std::cout, std::endl;
using std::exception;

class IShapeTextDataProvider {
private:
    int _numberOfShape;
public:
    IShapeTextDataProvider();
    int numberOfShape() const;
public:
    static vector<shared_ptr<IShape>> read(string, ParserFactory);
};