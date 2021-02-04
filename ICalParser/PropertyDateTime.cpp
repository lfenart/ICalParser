module Ast;

import std.core;
import Datatype;

namespace ast {

PropertyDateTime::PropertyDateTime(const datatype::DateTime& val, const std::map<std::string, std::string>& _params)
	: value(val)
{
	params = _params;
}

const datatype::DateTime& PropertyDateTime::get_value() const
{
	return value;
}

}
