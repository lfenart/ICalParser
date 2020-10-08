module Ast;

import std.core;

namespace ast {

const std::vector<std::unique_ptr<NodeComponent>>& NodeComponent::get_components() const
{
	return components;
}

}
