module Ast;

import std.core;

namespace ast {

PropertySummary::PropertySummary(const std::string& val, const std::map<std::string, std::string>& params)
	: PropertyString(val, params)
{
}

void PropertySummary::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_summary(*this);
}

}
