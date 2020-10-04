import std.core;
import Parser;
import NodeFactory;

namespace parser {

const NodeFactory& Parser::get_factory() const
{
	return NodeFactory::get_instance();
}

}
