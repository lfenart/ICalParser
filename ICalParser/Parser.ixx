export module Parser;

import std.core;
import Ast;

export namespace parser {

class NodeFactory {
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

class Parser {
public:
	virtual std::unique_ptr<ast::Node> parse(std::istream&) const = 0;
	const NodeFactory& get_factory() const;
};

class CalendarParser : public Parser {
public:
	std::unique_ptr<ast::Node> parse(std::istream&) const;
};

}
