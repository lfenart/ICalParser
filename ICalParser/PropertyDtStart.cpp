module Ast;

import std.core;

namespace ast {

PropertyDtStart::PropertyDtStart(const datatype::DateTime& val, const std::map<std::string, std::string>& params)
	: PropertyDateTime(val, params)
{
}

void PropertyDtStart::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_dt_start(*this);
}

}
