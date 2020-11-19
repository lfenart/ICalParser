module Parser;

import std.core;
import Ast;
import Exception;

namespace parser {

VCalendarParser::VCalendarParser()
{
	add_component_parser("VEVENT", std::make_unique<VEventParser>());

	// PropertyString
	add_property("METHOD");
	add_property("PRODID");
	add_property("VERSION");
	add_property("CALSCALE");
}

const std::string VCalendarParser::get_name() const
{
	return "VCALENDAR";
}

ast::Component::uptr VCalendarParser::create_component() const
{
	return get_factory().create_vcalendar();
}

}
