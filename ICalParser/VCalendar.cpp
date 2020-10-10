module Ast;

import std.core;

namespace ast {

const std::vector<std::unique_ptr<VComponent>>& VCalendar::get_components() const
{
	return components;
}

}
