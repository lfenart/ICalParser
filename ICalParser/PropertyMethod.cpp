module Ast;

import std.core;

namespace ast {

PropertyMethod::PropertyMethod(const std::string& val)
	: PropertyString(val)
{
}

void PropertyMethod::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_method(*this);
}

}
