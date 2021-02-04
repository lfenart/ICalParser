module Parser;

import std.core;
import Ast;

namespace parser {

VJournalParser::VJournalParser()
{
	// PropertyString
	add_property("DESCRIPTION");
	add_property("SUMMARY");
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

const std::string VJournalParser::get_name() const
{
	return "VJOURNAL";
}

ast::Component::uptr VJournalParser::create_component() const
{
	return get_factory().create_vjournal();
}

}
