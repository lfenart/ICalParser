module Ast;

import std.core;

namespace ast {

PropertyString::PropertyString(const std::string& val)
	: value(val)
{
}

const std::string& PropertyString::get_value() const
{
	return value;
}

}
