export module Ast;

import std.core;

namespace ast {

export class Node {
public:
	const std::vector<std::unique_ptr<Node>>& get_children() const;
	void add_child(std::unique_ptr<Node>);

private:
	std::vector<std::unique_ptr<Node>> children;
};

export class NodeCalendar : public Node {
};

}
