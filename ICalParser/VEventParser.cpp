module Parser;

import std.core;
import Ast;

namespace parser {

VEventParser::VEventParser()
{
	add_component_parser("VALARM", std::make_unique<VAlarmParser>());

	// PropertyString
	add_property("DESCRIPTION");
	add_property("SUMMARY");
	add_property("LOCATION");
	add_property("UID");
	add_property("ATTENDEE");

	// PropertyDate
	add_property("DTSTART");
	add_property("DTSTAMP");
	add_property("DTEND");
	add_property("CREATED");
	add_property("LAST-MODIFIED");

	// PropertyInt
	add_property("SEQUENCE");
}

const std::string VEventParser::get_name() const
{
	return "VEVENT";
}

ast::Component::uptr VEventParser::create_component() const
{
	return get_factory().create_vevent();
}

}
