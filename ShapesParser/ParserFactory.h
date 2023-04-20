#pragma once
#include "Object.h"
#include "IShape.h"
#include "IParser.h"
#include <map>

class ParserFactory : public Object {
private:
	map<string, IParser*> _prototypes;
public:
	void registerWith(string, IParser*);
	IParser* select(string type);
	string toString();
};