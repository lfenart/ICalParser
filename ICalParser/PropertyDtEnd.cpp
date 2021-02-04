module Ast;

import std.core;

namespace ast {

PropertyDtEnd::PropertyDtEnd(const datatype::DateTime& val, const std::map<std::string, std::string>& params)
	: PropertyDateTime(val, params)
{
}

void PropertyDtEnd::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_dt_end(*this);
}

}
