module Ast;

import std.core;

namespace ast {

PropertyLastModified::PropertyLastModified(const datatype::DateTime& val, const std::map<std::string, std::string>& params)
	: PropertyDateTime(val, params)
{
}

void PropertyLastModified::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_last_modified(*this);
}

}
