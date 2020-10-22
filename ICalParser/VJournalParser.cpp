module Parser;

import std.core;
import Ast;

namespace parser {

VJournalParser::VJournalParser() { }

const std::string& VJournalParser::get_name() const
{
	return "VJOURNAL";
}

ast::Component::uptr VJournalParser::create_node() const
{
	return get_factory().create_vjournal();
}

}
