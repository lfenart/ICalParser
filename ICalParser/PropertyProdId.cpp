module Ast;

import std.core;

namespace ast {

PropertyProdId::PropertyProdId(const std::string& val, const std::map<std::string, std::string>& params)
	: PropertyString(val, params)
{
}

void PropertyProdId::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_prod_id(*this);
}

}
