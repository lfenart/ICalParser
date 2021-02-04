module Parser;

import std.core;

namespace parser {

PropertyHelper::PropertyHelper(std::string _name, std::string _value, std::map<std::string, std::string> _parameters)
	: name(_name)
	, value(_value)
	, parameters(_parameters)
{
}

std::string PropertyHelper::get_name() const
{
	return name;
}

std::string PropertyHelper::get_value() const
{
	return value;
}

std::map<std::string, std::string> PropertyHelper::get_parameters() const
{
	return parameters;
}

}
