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

Property::uptr NodeFactory::create_property(const std::string& key, const std::string& value, const std::map<std::string, std::string>& params) const
{
	if (key == "DESCRIPTION") {
		return std::make_unique<PropertyDescription>(value, params);
	}
	if (key == "SUMMARY") {
		return std::make_unique<PropertySummary>(value, params);
	}
	if (key == "LOCATION") {
		return std::make_unique<PropertyLocation>(value, params);
	}
	if (key == "UID") {
		return std::make_unique<PropertyUid>(value, params);
	}
	if (key == "METHOD") {
		return std::make_unique<PropertyMethod>(value, params);
	}
	if (key == "PRODID") {
		return std::make_unique<PropertyProdId>(value, params);
	}
	if (key == "VERSION") {
		return std::make_unique<PropertyVersion>(value, params);
	}
	if (key == "CALSCALE") {
		return std::make_unique<PropertyCalScale>(value, params);
	}
	if (key == "ATTENDEE") {
		return std::make_unique<PropertyAttendee>(value, params);
	}
	if (key == "DTSTART") {
		return std::make_unique<PropertyDtStart>(value, params);
	}
	if (key == "DTSTAMP") {
		return std::make_unique<PropertyDtStamp>(value, params);
	}
	if (key == "DTEND") {
		return std::make_unique<PropertyDtEnd>(value, params);
	}
	if (key == "CREATED") {
		return std::make_unique<PropertyCreated>(value, params);
	}
	if (key == "LAST-MODIFIED") {
		return std::make_unique<PropertyLastModified>(value, params);
	}
	if (key == "SEQUENCE") {
		return std::make_unique<PropertySequence>(std::stoll(value), params);
	}
	// TODO: add properties
	throw exception::UnknownPropertyError(key);
}

}
