#include "ParserFactory.h"
#include "IShape.h"

/// <summary>
/// Register type of shapes available for the program
/// </summary>
/// <param name="type"></param>
/// <param name="parser"></param>
void ParserFactory::registerWith(string type, shared_ptr<IParser> parser)
{
	_prototypes.insert({ type, parser });
}

/// <summary>
/// Get a type of shape and select the corresponding parser of that shape.
/// If shape type is not available, return a null parser.
/// </summary>
/// <param name="type"></param>
/// <returns>a parser of input shape type</returns>
shared_ptr<IParser> ParserFactory::select(string type)
{
	shared_ptr<IParser> parser = nullptr;
	if (_prototypes.contains(type)) // If this type has been registered
	{
		parser = _prototypes[type]; // choose the corresponding parser
	}
	return parser;
}

/// <summary>
/// Display Parser Factory
/// </summary>
/// <returns>string "ParserFactory"</returns>
string ParserFactory::toString()
{
	return "ParserFactory";
}