module Ast;

import std.core;

namespace ast {

const std::vector<Component::uptr>& Component::get_components() const
{
	return components;
}

}
