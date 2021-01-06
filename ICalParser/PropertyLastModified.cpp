module Ast;

import std.core;

namespace ast {

PropertyLastModified::PropertyLastModified(const datatype::DateTime& val)
	: PropertyDateTime(val)
{
}

void PropertyLastModified::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_last_modified(*this);
}

}
