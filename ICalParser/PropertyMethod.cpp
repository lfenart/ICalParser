module Ast;

import std.core;

namespace ast {

PropertyMethod::PropertyMethod(const std::string& val, const std::map<std::string, std::string>& params)
	: PropertyString(val, params)
{
}

void PropertyMethod::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_method(*this);
}

}
