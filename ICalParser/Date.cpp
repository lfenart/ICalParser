module Datatype;

import std.core;

namespace datatype {

Date::Date(const std::string& val)
	: value(val)
{
}

std::ostream& Date::print_on(std::ostream& out) const
{
	return out << value;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	return date.print_on(out);
}

}
