module Parser;

import std.core;
import Ast;

namespace parser {

ast::VCalendar::uptr NodeFactory::create_node_calendar() const
{
	return std::make_unique<ast::VCalendar>();
}

ast::ICal::uptr NodeFactory::create_node_ical() const
{
	return std::make_unique<ast::ICal>();
}

}
