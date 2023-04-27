#include "ParserFactory.h"
#include "IShape.h"
#include <map>

void ParserFactory::registerWith(string type, shared_ptr<IParser> parser)
{
	_prototypes.insert({ type, parser });
}

shared_ptr<IParser> ParserFactory::select(string type)
{
	shared_ptr<IParser> parser = nullptr;
	if (_prototypes.contains(type)) // If this type has been registered
	{
		parser = _prototypes[type]; // choose the corresponding parser
	}
	return parser;
}

string ParserFactory::toString()
{
	return "ParserFactory";
}