module Ast;

import std.core;

namespace ast {

const std::map<std::string, std::string>& Property::get_params() const
{
	return params;
}

}
