module Ast;

import std.core;

namespace ast {

PropertyVersion::PropertyVersion(const std::string& val)
	: PropertyString(val)
{
}

void PropertyVersion::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_version(*this);
}

}
