module Ast;

import std.core;

namespace ast {

PropertyDtEnd::PropertyDtEnd(const datatype::Date& val)
	: PropertyDate(val)
{
}

void PropertyDtEnd::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_dt_end(*this);
}

}
