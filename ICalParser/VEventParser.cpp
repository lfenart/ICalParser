module Parser;

import std.core;
import Ast;

namespace parser {

VEventParser::VEventParser()
{
	add_component_parser("VALARM", std::make_unique<VAlarmParser>());

	// PropertyString
	add_property("DESCRIPTION");

	// PropertyDate
	add_property("DTSTART");

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
