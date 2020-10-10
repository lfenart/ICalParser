export module Parser;

import std.core;
import Ast;

export namespace parser {

class NodeFactory;
class Parser;
class ICalParser;
class CalendarParser;
class ComponentParser;
class UnknownComponentParser;

class NodeFactory {
public:
	ast::VCalendar::uptr create_node_calendar() const;
	ast::ICal::uptr create_node_ical() const;
};

class Parser {
public:
	virtual ~Parser() = default;

	virtual ast::Node::uptr parse(std::istream&) const = 0;

protected:
	const NodeFactory& get_factory() const;

private:
	NodeFactory factory;
};

class UnknownComponentParser {
public:
	void parse(std::istream&, const char*) const;
};

class ComponentParser : public Parser {
private:
	UnknownComponentParser unknownComponentParser;
};

class CalendarParser : public Parser {
public:
	CalendarParser() = default;
	virtual ~CalendarParser() = default;

	ast::Node::uptr parse(std::istream&) const override;

private:
	UnknownComponentParser unknownComponentParser;
};

class ICalParser : public Parser {
public:
	ICalParser() = default;
	virtual ~ICalParser() = default;

	ast::Node::uptr parse(std::istream&) const override;

private:
	CalendarParser calendarParser;
};

}
