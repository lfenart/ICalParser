module Parser;

import std.core;
import Ast;
import Exception;

namespace parser {

VCalendarParser::VCalendarParser()
{
	add_component_parser("VEVENT", std::make_unique<VEventParser>());
}

const char* VCalendarParser::get_name() const
{
	return "VCALENDAR";
}

}
