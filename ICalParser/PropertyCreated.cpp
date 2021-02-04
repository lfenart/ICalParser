module Ast;

import std.core;

namespace ast {

PropertyCreated::PropertyCreated(const datatype::DateTime& val, const std::map<std::string, std::string>& params)
	: PropertyDateTime(val, params)
{
}

void PropertyCreated::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_created(*this);
}

}
