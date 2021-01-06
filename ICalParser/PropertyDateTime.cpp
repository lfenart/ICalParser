module Ast;

import std.core;
import Datatype;

namespace ast {

PropertyDateTime::PropertyDateTime(const datatype::DateTime& val)
	: value(val)
{
}

const datatype::DateTime& PropertyDateTime::get_value() const
{
	return value;
}

}
