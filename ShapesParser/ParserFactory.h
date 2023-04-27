#pragma once
#include "Object.h"
#include "IShape.h"
#include "IParser.h"
#include <map>

using std::map;

class ParserFactory : public Object {
private:
	map<string, shared_ptr<IParser>> _prototypes;
public:
	void registerWith(string, shared_ptr<IParser>);
	shared_ptr<IParser> select(string type);
	string toString();
};