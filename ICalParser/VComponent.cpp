module Ast;

import std.core;

namespace ast {

const std::vector<VComponent::uptr>& VComponent::get_components() const
{
	return components;
}

}
