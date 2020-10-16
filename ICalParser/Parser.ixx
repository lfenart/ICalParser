export module Parser;

import std.core;
import Ast;

namespace parser {

export class Parser;
export class ICalParser;
export class CalendarParser;
export class ComponentParser;
export class UnknownComponentParser;

class Parser {
public:
	virtual ~Parser() = default;

	virtual ast::Node::uptr parse(std::istream&) const = 0;

protected:
	const ast::NodeFactory& get_factory() const;
	void parse_unknown_component(std::istream&, const char*) const;

private:
	ast::NodeFactory factory;
};

class ComponentParser : public Parser {
};

class VCalendarParser : public ComponentParser {
public:
	VCalendarParser() = default;
	virtual ~VCalendarParser() = default;

	ast::Node::uptr parse(std::istream&) const override;
};

class ICalParser : public Parser {
public:
	ICalParser() = default;
	virtual ~ICalParser() = default;

	ast::Node::uptr parse(std::istream&) const override;

private:
	VCalendarParser calendar_parser;
};

}
