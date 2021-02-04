module Ast;

import std.core;

namespace ast {

PropertyString::PropertyString(const std::string& val, const std::map<std::string, std::string>& _params)
	: value(val)
{
	params = _params;
}

const std::string& PropertyString::get_value() const
{
	return value;
}

}
