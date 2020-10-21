module Parser;

import std.core;
import Ast;

namespace ast {

ICal::uptr NodeFactory::create_ical() const
{
	return std::make_unique<ast::ICal>();
}

VCalendar::uptr NodeFactory::create_vcalendar() const
{
	return std::make_unique<ast::VCalendar>();
}

VEvent::uptr NodeFactory::create_vevent() const
{
	return std::make_unique<ast::VEvent>();
}

VAlarm::uptr NodeFactory::create_valarm() const
{
	return std::make_unique<ast::VAlarm>();
}

}
