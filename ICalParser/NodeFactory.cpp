module Ast;

import std.core;
import Exception;

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
	if (key == "SUMMARY") {
		return std::make_unique<PropertySummary>(value);
	}
	if (key == "LOCATION") {
		return std::make_unique<PropertyLocation>(value);
	}
	if (key == "UID") {
		return std::make_unique<PropertyUid>(value);
	}
	if (key == "METHOD") {
		return std::make_unique<PropertyMethod>(value);
	}
	if (key == "PRODID") {
		return std::make_unique<PropertyProdId>(value);
	}
	if (key == "VERSION") {
		return std::make_unique<PropertyVersion>(value);
	}
	if (key == "CALSCALE") {
		return std::make_unique<PropertyCalScale>(value);
	}
	if (key == "DTSTART") {
		return std::make_unique<PropertyDtStart>(value);
	}
	if (key == "DTSTAMP") {
		return std::make_unique<PropertyDtStamp>(value);
	}
	if (key == "DTEND") {
		return std::make_unique<PropertyDtEnd>(value);
	}
	if (key == "CREATED") {
		return std::make_unique<PropertyCreated>(value);
	}
	if (key == "LAST-MODIFIED") {
		return std::make_unique<PropertyLastModified>(value);
	}
	if (key == "SEQUENCE") {
		return std::make_unique<PropertySequence>(std::stoll(value));
	}
	// TODO: add properties
	throw exception::UnknownPropertyError(key);
}

}
