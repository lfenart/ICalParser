module Parser;

import std.core;
import Ast;

namespace parser {

VJournalParser::VJournalParser()
{
	// PropertyString
	add_property("DESCRIPTION");

	// PropertyDate
	add_property("DTSTART");

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
