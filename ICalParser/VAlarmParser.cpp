module Parser;

import std.core;
import Ast;

namespace parser {

VAlarmParser::VAlarmParser() { }

const std::string VAlarmParser::get_name() const
{
	return "VALARM";
}

ast::Component::uptr VAlarmParser::create_node() const
{
	return get_factory().create_valarm();
}

}
