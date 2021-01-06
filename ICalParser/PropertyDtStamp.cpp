module Ast;

import std.core;

namespace ast {

PropertyDtStamp::PropertyDtStamp(const datatype::DateTime& val)
	: PropertyDateTime(val)
{
}

void PropertyDtStamp::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_dt_stamp(*this);
}

}
