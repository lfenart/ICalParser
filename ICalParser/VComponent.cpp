module Ast;

import std.core;

namespace ast {

const std::vector<std::unique_ptr<VComponent>>& VComponent::get_components() const
{
	return components;
}

}
