module Ast;

import std.core;

namespace ast {

PropertyInt::PropertyInt(long long val)
	: value(val)
{
}

long long PropertyInt::get_value() const
{
	return value;
}

}
