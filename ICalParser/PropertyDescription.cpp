module Ast;

import std.core;

namespace ast {

PropertyDescription::PropertyDescription(const std::string& val)
	: PropertyString(val)
{
}

void PropertyDescription::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_description(*this);
}

}