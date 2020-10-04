export module CalendarParser;

import std.core;
import Parser;
import Node;
import NodeFactory;

namespace parser {

export class CalendarParser : public Parser {
public:
	std::unique_ptr<ast::Node> parse(std::istream&) const;
};

}