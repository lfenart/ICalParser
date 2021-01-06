module Ast;

import std.core;

namespace ast {

PropertyDtStart::PropertyDtStart(const datatype::DateTime& val)
	: PropertyDateTime(val)
{
}

void PropertyDtStart::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_dt_start(*this);
}

}
