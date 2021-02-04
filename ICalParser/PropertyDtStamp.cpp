module Ast;

import std.core;

namespace ast {

PropertyDtStamp::PropertyDtStamp(const datatype::DateTime& val, const std::map<std::string, std::string>& params)
	: PropertyDateTime(val, params)
{
}

void PropertyDtStamp::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_dt_stamp(*this);
}

}
