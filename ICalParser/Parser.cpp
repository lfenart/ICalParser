module Parser;

import std.core;
import Ast;

namespace parser {

const NodeFactory& Parser::get_factory() const
{
	return NodeFactory::get_instance();
}

}
