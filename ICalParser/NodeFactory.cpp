module Parser;

import std.core;
import Ast;

namespace ast {

VCalendar::uptr NodeFactory::create_node_calendar() const
{
	return std::make_unique<ast::VCalendar>();
}

ICal::uptr NodeFactory::create_node_ical() const
{
	return std::make_unique<ast::ICal>();
}

}
