module Parser;

import std.core;
import Ast;

namespace parser {

VEventParser::VEventParser()
{
	add_component_parser("VALARM", std::make_unique<VAlarmParser>());
}

const char* VEventParser::get_name() const
{
	return "VEVENT";
}

}
