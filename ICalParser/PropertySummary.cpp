module Ast;

import std.core;

namespace ast {

PropertySummary::PropertySummary(const std::string& val)
	: PropertyString(val)
{
}

void PropertySummary::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_summary(*this);
}

}
