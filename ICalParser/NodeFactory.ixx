export module NodeFactory;

import std.core;
import Node;

namespace parser {

export class NodeFactory {
public:
	static const NodeFactory& get_instance()
	{
		static NodeFactory instance;
		return instance;
	};
	NodeFactory(NodeFactory const&) = delete;
	void operator=(NodeFactory const&) = delete;

	std::unique_ptr<ast::Node> create_node_calendar() const;

private:
	NodeFactory();
};

}
