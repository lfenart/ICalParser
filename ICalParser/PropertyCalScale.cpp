module Ast;

import std.core;

namespace ast {

PropertyCalScale::PropertyCalScale(const std::string& val, const std::map<std::string, std::string>& params)
	: PropertyString(val, params)
{
}

void PropertyCalScale::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_cal_scale(*this);
}

}
