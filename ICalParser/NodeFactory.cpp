module Ast;

import std.core;

namespace ast {

ICal::uptr NodeFactory::create_ical() const
{
	return std::make_unique<ast::ICal>();
}

VCalendar::uptr NodeFactory::create_vcalendar() const
{
	return std::make_unique<ast::VCalendar>();
}

VAlarm::uptr NodeFactory::create_valarm() const
{
	return std::make_unique<ast::VAlarm>();
}

VEvent::uptr NodeFactory::create_vevent() const
{
	return std::make_unique<ast::VEvent>();
}

VJournal::uptr NodeFactory::create_vjournal() const
{
	return std::make_unique<ast::VJournal>();
}

Property::uptr NodeFactory::create_property(const std::string& key, const std::string& value) const
{
	if (key == "DESCRIPTION") {
		return std::make_unique<PropertyDescription>(value);
	}
	// TODO: add properties
	// TODO: throw better exception
	throw std::runtime_error("No such property");
}

}
