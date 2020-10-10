module Parser;

import std.core;
import Ast;

namespace parser {

std::unique_ptr<ast::VCalendar> NodeFactory::create_node_calendar() const
{
	return std::make_unique<ast::VCalendar>();
}

std::unique_ptr<ast::NodeICal> NodeFactory::create_node_ical() const
{
	return std::make_unique<ast::NodeICal>();
}

}
