module Ast;

import std.core;

namespace ast {

PropertyVersion::PropertyVersion(const std::string& val, const std::map<std::string, std::string>& params)
	: PropertyString(val, params)
{
}

void PropertyVersion::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_version(*this);
}

}
