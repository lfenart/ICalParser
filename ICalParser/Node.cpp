import std.core;
import Node;

namespace ast {

const std::vector<std::unique_ptr<Node>>& Node::get_children() const
{
	return children;
}

void Node::add_child(std::unique_ptr<Node> child)
{
	children.push_back(std::move(child));
}

}
