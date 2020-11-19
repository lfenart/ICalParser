module Ast;

import std.core;

namespace ast {

PropertyCalScale::PropertyCalScale(const std::string& val)
	: PropertyString(val)
{
}

void PropertyCalScale::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_cal_scale(*this);
}

}
