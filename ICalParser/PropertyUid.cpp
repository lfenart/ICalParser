module Ast;

import std.core;

namespace ast {

PropertyUid::PropertyUid(const std::string& val, const std::map<std::string, std::string>& params)
	: PropertyString(val, params)
{
}

void PropertyUid::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_uid(*this);
}

}
