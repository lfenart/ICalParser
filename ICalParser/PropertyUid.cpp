module Ast;

import std.core;

namespace ast {

PropertyUid::PropertyUid(const std::string& val)
	: PropertyString(val)
{
}

void PropertyUid::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_uid(*this);
}

}
