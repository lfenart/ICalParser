module Parser;

import std.core;
import Ast;

namespace parser {

VAlarmParser::VAlarmParser()
{
	add_property("DESCRIPTION");
}

const std::string VAlarmParser::get_name() const
{
	return "VALARM";
}

ast::Component::uptr VAlarmParser::create_component() const
{
	return get_factory().create_valarm();
}

}
