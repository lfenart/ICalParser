import std.core;
import NodeFactory;
import Node;
import NodeCalendar;

namespace parser {

NodeFactory::NodeFactory() { }

std::unique_ptr<ast::Node> NodeFactory::create_node_calendar() const
{
	return std::make_unique<ast::NodeCalendar>();
}

}
