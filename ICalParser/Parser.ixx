export module Parser;

import std.core;
import Node;
import NodeFactory;

namespace parser {

export class Parser {
public:
	virtual std::unique_ptr<ast::Node> parse(std::istream&) const = 0;
	const NodeFactory& get_factory() const;
};

}
