module Ast;

import std.core;

namespace ast {

PropertyLocation::PropertyLocation(const std::string& val)
	: PropertyString(val)
{
}

void PropertyLocation::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_location(*this);
}

}
