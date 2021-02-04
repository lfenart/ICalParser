module Ast;

import std.core;

namespace ast {

PropertyLocation::PropertyLocation(const std::string& val, const std::map<std::string, std::string>& params)
	: PropertyString(val, params)
{
}

void PropertyLocation::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_location(*this);
}

}
