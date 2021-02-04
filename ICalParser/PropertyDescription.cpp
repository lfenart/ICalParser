module Ast;

import std.core;

namespace ast {

PropertyDescription::PropertyDescription(const std::string& val, const std::map<std::string, std::string>& params)
	: PropertyString(val, params)
{
}

void PropertyDescription::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_description(*this);
}

}
