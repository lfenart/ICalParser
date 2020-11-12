module Ast;

import std.core;
import Datatype;

namespace ast {

PropertyDate::PropertyDate(const datatype::Date& val)
	: value(val)
{
}

const datatype::Date& PropertyDate::get_value() const
{
	return value;
}

}
