module Ast;

import std.core;

namespace ast {

PropertyProdId::PropertyProdId(const std::string& val)
	: PropertyString(val)
{
}

void PropertyProdId::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_prod_id(*this);
}

}
