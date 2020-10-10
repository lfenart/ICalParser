module Ast;

import std.core;

namespace ast {

const std::vector<VComponent::uptr>& VCalendar::get_components() const
{
	return components;
}

}
