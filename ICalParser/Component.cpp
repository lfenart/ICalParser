module Ast;

import std.core;

namespace ast {

const std::vector<Component::uptr>& Component::get_components() const
{
	return components;
}

void Component::add_component(Component::uptr component)
{
	components.push_back(std::move(component));
}

const std::vector<Property::uptr>& Component::get_properties() const
{
	return properties;
}

void Component::add_property(Property::uptr prop)
{
	properties.push_back(std::move(prop));
}

}
