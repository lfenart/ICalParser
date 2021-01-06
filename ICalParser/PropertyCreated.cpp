module Ast;

import std.core;

namespace ast {

PropertyCreated::PropertyCreated(const datatype::DateTime& val)
	: PropertyDateTime(val)
{
}

void PropertyCreated::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_created(*this);
}

}
