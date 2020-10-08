module Parser;

import std.core;

namespace parser {

const NodeFactory& Parser::get_factory() const
{
	return factory;
}

}
