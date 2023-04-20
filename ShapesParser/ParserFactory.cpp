#include "ParserFactory.h"
#include "IShape.h"
#include <map>

void ParserFactory::registerWith(string type, IParser* parser)
{
	_prototypes.insert({ type, parser });
}

IParser* ParserFactory::select(string type)
{
	IParser* parser = nullptr;
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