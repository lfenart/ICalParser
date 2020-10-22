module Parser;

import std.core;
import Ast;

namespace parser {

VEventParser::VEventParser()
{
	add_component_parser("VALARM", std::make_unique<VAlarmParser>());
}

const std::string& VEventParser::get_name() const
{
	return "VEVENT";
}

ast::Component::uptr VEventParser::create_node() const
{
	return get_factory().create_vevent();
}

}
