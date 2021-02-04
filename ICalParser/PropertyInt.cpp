module Ast;

import std.core;

namespace ast {

PropertyInt::PropertyInt(long long val, const std::map<std::string, std::string>& _params)
	: value(val)
{
	params = _params;
}

long long PropertyInt::get_value() const
{
	return value;
}

}
